#include<fstream>
#include<iostream>
#include "lexer.cpp"
#include "parser.cpp"
#include "intpr.cpp"

std::vector<std::vector<lexer::Token>> readFile(const char* filename) {
    std::string line;
    std::vector<std::vector<lexer::Token>> tokens;
    std::ifstream file(filename);

    while (getline(file, line)) {
        line += "\n";
        tokens.push_back(lexer::tokenize(line));
    }
    file.close();

    return tokens;

}

void showlist(std::vector<lexer::Token> &vect){
    std::cout<<"[";
    for(auto it: vect){
        if (it.token == "\n")
            std::cout<<"'\\n'";
        else
            std::cout<<it.token<<", ";
    }
    std::cout<<"]\n";
}

int main(int argc, char *argv[]){
    auto tokens = readFile(argv[1]);   // code from the target file

    for(auto it1: tokens){
        showlist(it1);
    }

    std::vector<parser::BaseNode*> AST;
    parser::Parser parser(tokens, AST);

    intpr::interpret(AST);

}
