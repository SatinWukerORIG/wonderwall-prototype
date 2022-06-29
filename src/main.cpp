#include<fstream>
#include "lexer.cpp"
#include "parser.cpp"
#include "intpr.cpp"

std::vector<std::vector<lexer::Token>> readFile(const char* fname) {
    std::string line;
    std::ifstream file(fname);
    std::vector<std::vector<lexer::Token>> tokens;

    while (getline(file, line)) {
        line += "\n";
        tokens.push_back(lexer::tokenize(line));
    }
    file.close();

    return tokens;
}

int main(int argc, char *argv[]){
    auto tokens = readFile(argv[1]);   // code from the target file

    // for(auto it1: tokens){
    //     intpr::showlist(it1);
    // }
    std::vector<parser::BaseNode*> *AST = new std::vector<parser::BaseNode*>();
    parser::Parser parser(&tokens, AST);

    intpr::interpret(*AST);
    delete AST;

}
