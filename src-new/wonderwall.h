/*Included by all files. Contains all constants*/
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
const char TT_STR = '0';
const char TT_I8 = '1';
const char TT_I16 = '2';
const char TT_I32 = '3';
const char TT_I64 = '4';
const char TT_I128 = '5';
const char TT_IINDEX = '6';
const char TT_U8 = '7';
const char TT_U16 = '8';
const char TT_U32 = '9';
const char TT_U64 = 'A';
const char TT_U128 = 'B';
const char TT_UIINDEX = 'C';
const char TT_IDFR = 'D';
