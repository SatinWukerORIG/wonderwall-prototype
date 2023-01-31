#pragma once
#include "wonderwall.h"
#include <memory>
#include <vector>
#include <algorithm>

class Executor{
private:

unsigned short int lines = 0;
std::vector<std::string> symbol_table {};


void tokenize() {
    unsigned short int i = 0;
    bool is_in_quote = false;
    std::string current_tok = "";
    char ch = ' ';
    while (i < src -> length()) {
        ch = (*src)[i];
        // next line
        if (ch == '\n') lines++;
        // comment
        else if(ch == '#'){
            i++;
            while((*src)[i] != '\n') i++;
        }
        // else if(ch >= '0' && ch <= '9'){

        // }
        else if(ch == '"'){
            i++;
            while((*src)[i] != '"' && i < src -> length()){
                current_tok += (*src)[i];
                i++;
            }
            std::cout<<"STR: "<<current_tok<<std::endl;
            current_tok.clear();
        }
        else {
            // Identifier
            while(!std::binary_search(OPERATORS.begin(), OPERATORS.end(), (*src)[i])
            && i < src -> length()){
                current_tok += (*src)[i];
                i++;
            }
            std::cout<<"IDFR: "<<current_tok<<std::endl;
            current_tok.clear();
        }
        i++;
    }

}
public:
    std::unique_ptr<std::string> src;

    void run() {
        tokenize();
    }
};