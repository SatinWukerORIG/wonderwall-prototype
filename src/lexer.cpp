#include<iostream>  // std::cout<<
#include<vector>    // std::vector<>
#include<string>    // std::string
#include<algorithm> // std::find()
#include "wonderwall.hpp"  // TT(token types), KEYWORDS[4]


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

    std::vector<Token> tokenize(std::string &text){
        std::vector<Token> tokens;  // return: tokens
        int quote_count;            // count of the char '

        std::string lastchar;       // variable to store the last token
        for (int i = 0; i < text.length(); i++) {
            if (text[i] == '#') break;
            if (text[i] == '\'') quote_count++;

            if ((text[i] == ' '||text[i] == '\n') && quote_count % 2 == 0)
            {
                //if (lastchar != " ")
                    tokens.push_back(Token(lastchar, get_type(lastchar)));

                lastchar.clear();

                if(text[i] == '\n')
                    tokens.push_back(Token("\n", TT_EOF));
            }
            else lastchar += text[i];
        }

        return tokens;

    }

}
