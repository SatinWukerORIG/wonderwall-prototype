#pragma once
#include <iostream>
#include <string>
#include <vector>

/* operators, sorted according their ascii values
this is for performing binary search in tokenize()
*/
const std::vector<char> OPERATORS {
    '\n', ' ', '%','\'', '(', ')', '*',
    '+', ',', '-', '.', '/', ':',
    '<', '>', '[', ']'
};