#include "wonderwall.h"
#include <algorithm>
#include <stdio.h>

namespace lexer{

struct Token{
    char ttype;
    std::string tvalue;
    Token(char type, std::string value): ttype(type), tvalue(value) {}
};

class Lexer{
private:
    unsigned int idx = 0; // index of the source string
    std::string src;

public:
    Lexer(std::string &src): src(src) {}

    unsigned short int lines = 0;

    Token get_tok() {

        const unsigned int src_len = src.length();
        std::string current_tok; // store the current token
        current_tok.reserve(4);
        char ch; // store the current char
        
        while(idx < src_len) {
            ch = src[idx];
            // comment
            if (ch == '#') {
                ++idx;
                while(src[idx] != '\n' && idx < src_len)
                    ++idx;
            }
            // new line
            else if (ch == '\n') {
                lines++;
            }
            // Tokenize number
            else if (ch > 47 && ch < 58) {
                while(src[idx] > 47 && src[idx] < 58 && idx < src_len) {
                    current_tok.push_back(src[idx]);
                    ++idx;
                }
                // parse number
                ++idx;
                return Token(TT_I32, current_tok);
                // current_tok.clear();
                // current_tok.shrink_to_fit();
            }
            // Tokenize string
            else if (ch == '"') {
                ++idx;
                while(src[idx] != '"' && idx < src_len){
                    current_tok.push_back(src[idx]);
                    ++idx;
                }
                // parse string
                ++idx;
                return Token(TT_STR, current_tok); // update buffer
                // current_tok.clear();
                // current_tok.shrink_to_fit();
            }
            // Tokenize identifier
            else if((ch >= 'A'&&ch<='Z')||(ch >= 'a'&&ch<='z')||ch=='_') {
                // Stop looping if the current ch is a delimiter/separator
                while(!std::binary_search(std::begin(DELIMITERS),
                std::end(DELIMITERS),
                src[idx]) && idx < src_len){
                    current_tok.push_back(src[idx]);
                    ++idx;
                }
                // if ch is a delimiter and does not equal to \n or space:
                if(src[idx] != ' ' && src[idx] != '\n'){
                    printf("TT_DELI %c\n", src[idx]);
                }

                ++idx;
                return Token(TT_IDFR, current_tok);
                // current_tok.clear();
                // current_tok.shrink_to_fit();
            }
            // Operator
            else if(std::binary_search(std::begin(OPERATORS),
            std::end(OPERATORS), ch))
            {
                if(ch != ' '){
                    //printf("TT_OP %c\n", ch);
                    ++idx;
                    return Token(TT_OP, std::string (1, ch));
                }
            }
            // Delimiter
            else if(std::binary_search(std::begin(DELIMITERS),
            std::end(DELIMITERS), ch))
            {
                if(ch != ' '){
                    ++idx;
                    return Token(TT_DELI, std::string (1, ch));
                }
            }
            // What the heck?
            else{
                return Token(TT_WTH, "");
            }
            ++idx;
        }
        // if there is nothing to return
        return Token(TT_EOF, "");
    }
};
}