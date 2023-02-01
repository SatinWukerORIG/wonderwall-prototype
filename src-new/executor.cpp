#pragma once
#include "wonderwall.h"
#include <memory>
#include <vector>
#include <algorithm>


class Token{
public:
    char ttype;
    std::string tvalue;
    Token(char type, std::string value): ttype(type), tvalue(value) {
        ttype = type;
        tvalue = value;
    }
};

class Executor{
private:

unsigned short int lines = 0;
std::vector<std::string> symbol_table {};


void tokenize() {
    unsigned short int i = 0;
    const unsigned int src_len = src.length();
    std::string current_tok;
    char ch;
    do {
        ch = src[i];
        // next line
        if (ch == '\n') lines++;
        // comment
        else if(ch == '#'){
            i++;
            while(src[i] != '\n') i++;
        }
        // Tokenize number
        else if (ch >= '0' && ch <= '9') {
            while(src[i] >= '0' && src[i] <= '9' && i < src_len){
                current_tok.push_back(src[i]);
                i++;
            }
            Token token(TT_I16, current_tok);
            //std::cout<<"token: "<<token.ttype<<token.tvalue<<std::endl;
            current_tok.clear();
        }
        // Tokenize string
        else if (ch == '"') {
            i++;
            while(src[i] != '"' && i < src_len){
                current_tok.push_back(src[i]);
                i++;
            }
            Token token(TT_STR, current_tok);
            //std::cout<<"token: "<<token.ttype<<token.tvalue<<std::endl;
            current_tok.clear();
        }
        // Tokenize identifier
        else {
            // Identifier
            while(!std::binary_search(OPERATORS.begin(), OPERATORS.end(), src[i])
            && i < src_len){
                current_tok.push_back(src[i]);
                i++;
            }
            Token token(TT_IDFR, current_tok);
            //std::cout<<"token: "<<token.ttype<<token.tvalue<<std::endl;
            current_tok.clear();
        }
        i++;
    }
    while (i++ < src_len);

}
public:
    std::string src;

    void run() {
        tokenize();
    }
};
