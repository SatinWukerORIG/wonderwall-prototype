#pragma once
#include "wonderwall.h"
#include "parser.cpp"
#include <memory>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iostream>


class Executor{
private:

unsigned short int lines = 0;

std::vector<std::vector<parser::Token>> ast; // abstract syntax tree

inline void parse_keywords(std::string &cur_idfr) {
    if (cur_idfr == "print") {
        ast.emplace_back(parser::make_print_tree(parser::Token('W',"")));
    }
    else if (cur_idfr == "store") {
        ast.emplace_back(parser::make_store_tree(
            parser::Token('I', ""),
            parser::Token('W', ""))
        );
    }
    else { // identifier: variable/func/... name
        //ast.back()[1] = cur_tok;
        parse_idfr(cur_idfr);
    }
}

inline void parse_idfr(std::string cur_idfr) { // parse identifier
    if (ast.back()[0].tvalue == "print"){
        std::cout<<"print identifier: "<<cur_idfr<<std::endl;
    }
    else if (ast.back()[0].tvalue == "store"){
        std::cout<<"store identifier: "<<cur_idfr<<std::endl;
    }
}

inline void parse_string(std::string& cur_string) {
    if(ast.back()[0].tvalue == "print"){
        ast.back()[1] = parser::Token('S', cur_string);
        std::cout<<"print string: "<<ast.back()[1].tvalue<<std::endl;
    }
    else if(ast.back()[0].tvalue == "store"){
        ast.back()[2] = parser::Token('S', cur_string);
        std::cout<<"store string: "<<ast.back()[2].tvalue<<std::endl;
    }
}

inline void parse_num(std::string& cur_num) {
    if(ast.back()[0].tvalue == "print"){
        ast.back()[1] = parser::Token('2', cur_num);
        std::cout<<"print num: "<<ast.back()[1].tvalue<<std::endl;
    }
    else if(ast.back()[0].tvalue == "store"){
        ast.back()[2] = parser::Token('2', cur_num);
        std::cout<<"store num: "<<ast.back()[2].tvalue<<std::endl;
    }
}

void tokenize() {
    ast.reserve(10);

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
            // parse number
            parse_num(current_tok);

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
            // parse string
            parse_string(current_tok);

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
            if((*src)[i] != ' ' && (*src)[i] != '\n'){
                printf("TT_DELI %c\n", (*src)[i]);
            }

            parse_keywords(current_tok);
            current_tok.clear();
            current_tok.shrink_to_fit();
        }
        // Operator
        else if(std::binary_search(std::begin(OPERATORS), std::end(OPERATORS), ch))
        {
            if(ch != ' '){
                printf("TT_OP %c\n", ch);
            }
        }
        // Delimiter
        else if(std::binary_search(std::begin(DELIMITERS), std::end(DELIMITERS), ch))
        {
            if(ch != ' '){
                printf("TT_DELI %c\n", ch);
            }
        }
        // What the heck?
        else{
            //printf("TT_WTH %c\n", ch);
        }
    }

}
public:
    std::unique_ptr<std::string> src;

    void run() {
        tokenize();
    }
};
