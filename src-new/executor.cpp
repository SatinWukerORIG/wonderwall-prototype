#pragma once
#include "wonderwall.h"
#include "trees.cpp"
#include <memory>
#include <stdio.h>
#include <vector>
#include <algorithm>


class Token{
public:
    char ttype;
    std::string tvalue;
    Token(char type, std::string value): ttype(type), tvalue(value) {}
};

class Executor{
private:

unsigned short int lines = 0;
std::vector<std::string> symbol_table {};

void tokenize() {

    std::vector<trees::BaseNode> cur_tree;
    cur_tree.reserve(10);

    unsigned short int treevec_idx = 0;

    const unsigned int src_len = src -> length();
    std::string current_tok; // store the current token
    current_tok.reserve(4);
    char ch; // store the current char
    for (unsigned short int i = 0; i < src_len; i++)
    {
        ch = (*src)[i];
        // comment
        if (ch == '#')
        {
            i++;
            while((*src)[i] != '\n' && i < src_len)
                i++;
        }
        // new line
        else if (ch == '\n')
        {
            lines++;
        }
        // Tokenize number
        else if (ch > 47 && ch < 58)
        {
            while((*src)[i] > 47 && (*src)[i] < 58 && i < src_len) {
                current_tok.push_back((*src)[i]);
                i++;
            }
            Token token(TT_I16, current_tok);
            printf("TT_I16 %s\n", current_tok.c_str());
            current_tok.clear();
            current_tok.shrink_to_fit();
        }
        // Tokenize string
        else if (ch == '"')
        {
            i++;
            while((*src)[i] != '"' && i < src_len){
                current_tok.push_back((*src)[i]);
                i++;
            }
            Token token(TT_STR, current_tok);
            printf("TT_STR %s\n", current_tok.c_str());
            current_tok.clear();
            current_tok.shrink_to_fit();
        }
        // Tokenize identifier
        else if((ch >= 'A'&&ch<='Z')||(ch >= 'a'&&ch<='z')||ch=='_')
        {
            // Stop looping if the current ch is a delimiter/separator
            while(!std::binary_search(std::begin(DELIMITERS),std::end(DELIMITERS),(*src)[i])
            && i < src_len){
                current_tok.push_back((*src)[i]);
                i++;
            }
            // if ch is a delimiter and does not equal to \n or space:
            if((*src)[i] != ' ' && (*src)[i] != '\n')
                printf("TT_DELI %c\n", (*src)[i]);

            Token token(TT_IDFR, current_tok);
            printf("TT_IDFR %s\n", current_tok.c_str());
            current_tok.clear();
            current_tok.shrink_to_fit();
        }
        // Operator
        else if(std::binary_search(std::begin(OPERATORS), std::end(OPERATORS), ch))
        {
            if(ch != ' ')
                printf("TT_OP %c\n", ch);
        }
        // Delimiter
        else if(std::binary_search(std::begin(DELIMITERS), std::end(DELIMITERS), ch))
        {
            if(ch != ' ')
                printf("TT_DELI %c\n", ch);
        }
        // What the heck?
        else{
            printf("TT_WTH %c\n", ch);
        }
    }

}
public:
    std::unique_ptr<std::string> src;

    void run() {
        tokenize();
    }
};
