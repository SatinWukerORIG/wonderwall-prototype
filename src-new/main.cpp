/* 1. base for all files
   2. constants: keywords/instructions */
#include "wonderwall.h"
// basic
#include <fstream>
#include <sstream>
#include <memory>

#include "executor.cpp"

// benchmark
#include <chrono>
/*
int parse_args(char** argv) {
    if (std::strcmp(argv[1], "a")) {
    }
    return 0;
}
*/

int main(int argc, char** argv){

    // ---BENCHMARCH---
    auto start = std::chrono::high_resolution_clock::now();
    // ---BENCHMARCH---

    std::string file_name = argv[1];
    // read src file to buffer: std::stringstream
    std::ifstream text(file_name);
    std::stringstream buffer;
    buffer << text.rdbuf();
    text.close();

    const std::string buffer_str = buffer.str();
    std::unique_ptr<Executor> exec = std::make_unique<Executor>();
    exec->src = std::make_unique<std::string>(buffer_str);
    exec->run();

    // ---BENCHMARCH---
    auto stop = std::chrono::high_resolution_clock::now();
    auto dr=std::chrono::duration_cast<std::chrono::microseconds>(stop-start);
    printf("execution time: %lld microsecs.\n", dr.count());
    // ---BENCHMARCH---
}
