#include<string>    // std::string
#include<algorithm> // std::find()
#include<stdexcept> // std::out_of_range()
#include<iostream>
#include "wonderwall.hpp"  // TT(token types), KEYWORDS={}

namespace lexer {

    class Token {   // a type for storing tokens. Token(token, type)
        public:
            std::string token, type;
            Token(std::string tok = " ", std::string typ = TT_MPT)
            : token(tok), type(typ) {}
    };
    bool is_int(const std::string &str) {
        std::string::const_iterator it = str.begin();
        while (it != str.end() && std::isdigit(*it)) ++it;
        return !str.empty() && it == str.end();
    }
    bool is_float(const std::string &str) {
        std::string::const_iterator it = str.begin();
        while (it != str.end() && (std::isdigit(*it) || *it == '.')) ++it;
        return !str.empty() && it == str.end();
    }
    bool is_op(std::string &str) {
        return std::find(OPERATORS, OPERATORS + 5, str) != OPERATORS + 5;
    }

    std::string get_type(std::string &str) {
        if (std::find(KEYWORDS, KEYWORDS + 5, str) != KEYWORDS + 5)
            return TT_KW;

        else if (str[0] == '\'' && str.back() == '\'')
            return TT_STR;
        else if (is_op(str))
            return TT_OP;
        else if (is_int(str) == 1)
            return TT_INT;
        else if (is_float(str) == 1) return TT_FLOAT;
        else return TT_ID;
    }

    class Lexer{
        private:

            int idx = 0;            // index of the text string
            int quote_count = 0;    // count of the char '

        public:
            const std::string &text;
            const int text_len = text.length();
            Lexer(const std::string &t) : text(t){}

            Token get_tok(){    // get/return next token
                if (idx >= text_len)
                    throw std::out_of_range("text[idx] out of range");
                if (text[idx] == '\n') {
                    idx++;
                    return Token("\n", TT_EOF);
                }
                while (text[idx] == ' ') idx++; // skip any white space

                std::string cur_word;    // variable to store the current token
                while(text[idx] != ' '&&text[idx] != '\n' || quote_count % 2 != 0){
                    if (text[idx] == '\'') quote_count++;
                    else cur_word += text[idx];
                    idx++;
                }

                return Token(cur_word, get_type(cur_word));
            };
    };

}
