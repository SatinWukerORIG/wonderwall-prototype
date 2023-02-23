#include <stdio.h>
#include <string>
#include <vector>

#include "lexer.cpp"
// lexer.cpp is already included

namespace parser {

class Parser{
private:
    lexer::Lexer Lex;
    void print_tok(lexer::Token tok){
        std::cout<<"Type: "<<tok.ttype<<" Value: " <<tok.tvalue<<std::endl;
    }

    void parse_instrc(lexer::Token tk) { // tk: token
        if (tk.tvalue == "print") {

        }
    }
    /*
    TODO: type check of an identifier: std::string
          will be invoked in parse() while() switch case: TT_IDFR
          return results: Built-in instruction(Keyword), Instruction/Function/Variable
    */
    char get_idfr_type(std::string& idfr) {
        
        return ' ';
    }
public:
    Parser(lexer::Lexer Lex): Lex(Lex){}

    void parse() { // start parsing. main loop
        unsigned int idx = 0;
        lexer::Token CurTok('W', "");
        while (1) {
            CurTok = Lex.get_tok();
            if (CurTok.ttype == TT_EOF) {
                break;
            }
            switch (CurTok.ttype) {
                case TT_IDFR: // identifier can be an instruction, function, or variable
                    parse_instrc(CurTok);
                    std::cout<<"IDFR: "<<CurTok.tvalue<<std::endl;
                    break;
                default:
                    std::cout<<CurTok.ttype<<": "<<CurTok.tvalue<<std::endl;
                
            }
        }
    }
};
};
