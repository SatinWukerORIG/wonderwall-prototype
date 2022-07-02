#include<time.h>
#include<fstream>
#include<string>
#include "lexer.cpp"
#include "parser.cpp"
#include "intpr.cpp"

std::string readFile(const char* fname) {
    std::string line, content;
    std::ifstream file(fname);

    while (getline(file, line)) {
        content = line + "\n";
    }
    file.close();

    return content;
}

int main(int argc, char *argv[]){
    int start = clock();
    std::string src = readFile(argv[1]);
    auto tokens = lexer::tokenize(src);   // code from the target file

    intpr::showlist(tokens);
    std::vector<parser::BaseNode*> *AST = new std::vector<parser::BaseNode*>();
    parser::Parser parser(&tokens, AST);

    //intpr::interpret(*AST);
    delete AST;

    std::cout<<"\nexecution time: "
        <<((float)clock() - start)/1000000<<"seconds.\n";

}
