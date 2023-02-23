#pragma once
#include "wonderwall.h"
// #include "lexer.cpp"
// "lexer.cpp" is included in "parser.cpp"
#include "parser.cpp"

#include <memory>
#include <stdio.h>


class Executor{

public:
    std::unique_ptr<std::string> src;

    void run() {
        lexer::Lexer wonderwall_lexer(*src);
        parser::Parser wonderwall_parser(wonderwall_lexer);
        wonderwall_parser.parse();
    }
};
