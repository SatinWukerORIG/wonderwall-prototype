#include <fstream>
#include "lexer.cpp"
#include "parser.cpp"

std::string readFile(const char* filename) {
    std::string content, line;
    std::ifstream file(filename);

    while (getline(file, line)) {
        content = content + line + "\n";
    }

    return content;
}


int main(int argc, char *argv[]){
    std::string text = readFile(argv[1]);   // code from the target file

    auto tokens = lexer::tokenize(text);

    std::vector<parser::ExprAST> AST;
    parser::Parser parser(tokens, AST);
    parser.parse();

}
