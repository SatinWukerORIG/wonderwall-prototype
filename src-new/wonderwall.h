/*Included by all files. Contains all constexprants*/
#pragma once
#include <iostream>
#include <string>
#include <cstring>
#include <vector>

/* operators, sorted according their ascii values
this is for performing binary search in tokenize()
*/
const std::vector<char> OPERATORS {
    '\n', ' ', '%','\'', '(', ')', '*',
    '+', ',', '-', '.', '/', ':',
    '<', '>', '[', ']'
};

// TT: Token Types
constexpr char TT_STR = 'S';
constexpr char TT_I8 = '1';
constexpr char TT_I16 = '2';
constexpr char TT_I32 = '3';
constexpr char TT_I64 = '4';
constexpr char TT_I128 = '5';
constexpr char TT_IINDEX = '6';
constexpr char TT_U8 = '7';
constexpr char TT_U16 = '8';
constexpr char TT_U32 = '9';
constexpr char TT_U64 = 'A';
constexpr char TT_U128 = 'B';
constexpr char TT_UIINDEX = 'C';
constexpr char TT_IDFR = 'D';
constexpr char TT_OP = 'O';
