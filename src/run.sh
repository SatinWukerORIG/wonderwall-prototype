#!/bin/bash
# chmod +x run.sh
clang++ -Oz main.cpp -o wonderwall.out -std=c++20
./wonderwall.out a.txt