#include<vector>
#include<string>
#include<memory>

/*
store msg 'Hello world!'
print msg
*/

/*
              AST
            /     \
    store_node    print_node
       /   \           |
     ID  value        args
    
*/

class ExprAST{
    public:
        virtual ~ExprAST() = default;
};

class IfNode : public ExprAST{
    public:
        std::unique_ptr<ExprAST> cond;
        std::unique_ptr<ExprAST> children;

        IfNode(std::unique_ptr<ExprAST> cond, std::unique_ptr<ExprAST> children)
        : cond(std::move(cond)), children(std::move(children)){}

};

class NumNode : public ExprAST{
    public:
        double val;

};

class BinOpNode : public ExprAST{
    public:
        std::unique_ptr<ExprAST> left, right;
        char op;

        BinOpNode(std::unique_ptr<ExprAST> left,
        std::unique_ptr<ExprAST> right, char oper)
        : left(std::move(left)), right(std::move(right)), op(oper){

        }
};


class AssignNode : public ExprAST{
    public:
        std::string name;
        std::unique_ptr<ExprAST> expr;
        AssignNode(std::string name, std::unique_ptr<ExprAST> expr) :
        name(name), expr(std::move(expr)) {

        }
};

/*
    LL(1) Parser
    Left to right, leftmost derivation parser
    adv(): Recursively get the next token
*/

class Parser{
    private:
        int idx = -1;
        Token cur_tok;             // Current token
        std::vector<Token> &tokens;

        void adv(){
            idx++;
            if (idx < tokens.size())
                cur_tok = tokens[idx];
        }

    public:
        std::vector<ExprAST> &AST;

        Parser(std::vector<Token> &toks, std::vector<ExprAST> &ast)
        : tokens(toks), AST(ast){}

        void parse(){
            
        }
};