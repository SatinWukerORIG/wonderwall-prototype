#include<iostream>
#include<vector>

using namespace std;

/*
store msg 'Hello world!'
print msg
*/

// void print_node(vector<string> *Node, vector<string> args);
// void assign_node(vector<string> *Node, name, vector<string> expr);
// void if_node(vector<string> *Node, vector<string> args);
// void while_node(vector<string> *Node, vector<string> args);

vector<string> parse(string text){
    vector<string> ast;     // return: abstract syntax tree

    int i = 0;              // index of the text string
    int quote_count = 0;    // count of the char '

    string lastchar;        // variable to store the last token

    while (i < text.length()) {
        if (text[i] == '\'') quote_count++;

        if (text[i] == ' ' && quote_count % 2 == 0)
        {
            ast.push_back(lastchar);
            lastchar = "";
        }
        else lastchar += text[i];

        i++;
    }

    return ast;
    
}

int main(int argc, char **argv){
    string text = "store msg 'Hello world!'\nprint msg";
    vector<string> ast = parse(text);
    for(int i = 0; i < ast.size(); i++){
        cout<<ast[i]<<'\n';
    }

}
