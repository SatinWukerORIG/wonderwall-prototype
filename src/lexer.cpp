#include<string>    // std::string
#include<algorithm> // std::find()
#include<stdexcept> // std::out_of_range()
#include "wonderwall.hpp"  // TT(token types), KEYWORDS={}

namespace lexer {

    class Token {   // a type for storing tokens. Token(token, type)
        public:
            std::string token, type;
            Token(std::string tok = " ", std::string typ = TT_MPT)
            : token(tok), type(typ) {}
    };

    class Lexer{
        private:

            int idx = 0;            // index of the text string
            int quote_count = 0;    // count of the char '

            bool is_int(std::string &str) {
                return str.find_first_not_of("0123456789") == std::string::npos;
            }
            bool is_float(std::string &str) {
                return str.find_first_not_of("0123456789.") == std::string::npos;
            }

            std::string get_type(std::string &str) {
                if (std::find(KEYWORDS, KEYWORDS + 5, str) != KEYWORDS + 5)
                    return TT_KW;

                else if (str[0] == '\'' && str.back() == '\'')
                    return TT_STR;

                else if (is_int(str))
                    return TT_INT;

                else if (is_float(str))
                    return TT_FLOAT;

                else
                    return TT_ID;

            }
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
                std::string cur_word;    // variable to store the current token
                while(text[idx] != ' '&&text[idx] != '\n' || quote_count % 2 != 0){
                    if (text[idx] == '\'') quote_count++;
                    else cur_word += text[idx];
                    idx++;
                }

                if (text[idx] == ' ')
                    idx++; // skip empty token

                return Token(cur_word, get_type(cur_word));
            };
    };

}
