#include <string>
#include <vector>

namespace parser {
    class Token{
    public:
        char ttype;
        std::string tvalue;
        Token(char type, std::string value): ttype(type), tvalue(value) {}
    };

    inline std::vector<Token> make_store_tree(Token var_name, Token value){
        // [name="store", var_name="", value=""]
        return {Token('K', "store"), var_name, value};
    }

    inline std::vector<Token> make_print_tree(Token value){
        // [name="print", value=""]
        return {Token('K', "print"), value};
    }

};
