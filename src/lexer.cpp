#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<array>
#include<ctype.h>
#include "wonderwall.hpp"


class Token {   // a type for storing tokens. Token(token, type)
    public:
        std::string token, type;
        Token(std::string tok = " ", std::string typ = TT_MPT)
        : token(tok), type(typ) {}
};


bool is_int(std::string &str) {
    return str.find_first_not_of("0123456789") == std::string::npos;
}
bool is_float(std::string &str) {
    return str.find_first_not_of("0123456789.") == std::string::npos;
}

std::string get_type(std::string &str) {
    if (str == "\n")
        return TT_EOF;

    else if (std::find(KEYWORDS, KEYWORDS + 4, str) != KEYWORDS + 4)
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

std::vector<Token> tokenize(std::string text){
    std::vector<Token> tokens;  // return: tokens

    int i = 0;              // index of the text string
    int quote_count = 0;    // count of the char '

    std::string lastchar;   // variable to store the last token
    while (i < text.length()) {
        if (text[i] == '\'') quote_count++;

        if ((text[i] == ' '||text[i] == '\n') && quote_count % 2 == 0)
        {
            tokens.push_back(Token(lastchar, get_type(lastchar)));
            lastchar.clear();

            if(text[i] == '\n') tokens.push_back(Token("\n", TT_EOF));
        }
        else lastchar += text[i];
        i++;
    }

    return tokens;

}
