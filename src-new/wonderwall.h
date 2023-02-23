/*Included by all files. Contains all constexprants*/
#pragma once
#include <iostream>
#include <string>
/* operators, sorted according their ascii values
this is for performing binary search in tokenize()
*/
constexpr char DELIMITERS[17] {
    '\n', ' ', '%','\'', '(', ')', '*',
    '+', ',', '-', '.', '/', ':',
    '<', '>', '[', ']'
};

constexpr char OPERATORS[13] {
    '%', '(', ')', '*',
    '+', '-', '.', '/', ':',
    '<', '>', '[', ']'
};

/* TT: Token Types */
constexpr char TT_STR = 'S';    // string

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

constexpr char TT_DELI = 'D';    // delimeter
constexpr char TT_OP = 'O';      // operator
constexpr char TT_IDFR = 'I';    // identifier
// constexpr char TT_KW = 'K';      // Keyword

constexpr char TT_WTH = 'W';     // ???
constexpr char TT_EOF = 'E';
