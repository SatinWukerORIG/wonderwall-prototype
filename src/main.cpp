#include "lexer.cpp"
#include "parser.cpp"

int main(int argc, char **argv){
    std::string text = "store msg 'Hello world!'\nprint msg";
    text += " ";
    auto tokens = tokenize(text);

    for(int i = 0; i < tokens.size(); i++){
        std::cout<<tokens[i].token<<" : "<<tokens[i].type<<"\n";
    }

    std::vector<ExprAST> AST;
    Parser parser(tokens, AST);

}