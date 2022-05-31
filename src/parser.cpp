#include<vector>  // std::vector<>
#include<string>  // std::string
#include<memory>  // std::unique_ptr<>

namespace parser {

    class ExprAST{
        public:
            virtual ~ExprAST() = default;
    };

    class PrintNode : public ExprAST {
        std::string name = "print";
        std::vector<lexer::Token> &expr;

        public:
            PrintNode(std::vector<lexer::Token> &expression)
            : expr(expression) {}
            
    };

    class IfNode : public ExprAST {
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
        Recursively get the next token
    */

    class Parser{
        private:
            int idx = -1;
            lexer::Token cur_tok;              // current token
            std::vector<lexer::Token> &tokens; // 

            void adv() {
                idx++;

                if (idx < tokens.size())
                    cur_tok = tokens[idx];
            }

            void skip(int offset) {
                idx += offset;
            }

            void parse_expr(){}

            void parse_kw()
            {
                if (cur_tok.token == "print") {
                    /*  print_node
                            |
                           expr    */
                    std::vector<lexer::Token> expr;
                    std::cout<<"print: ";
                    while(cur_tok.type != TT_EOF){
                        adv();
                        std::cout<<cur_tok.token<<" ";
                        expr.push_back(cur_tok);
                    }
                    // PrintNode(expr);
                }

                else if (cur_tok.token == "store") {
                    /*  store_node
                          /    \
                        name   expr */
                    std::vector<lexer::Token> expr;
                    std::cout<<"store: ";

                    adv();
                    while(cur_tok.type != TT_EOF){
                        adv();
                        std::cout<<cur_tok.token<<" ";
                        expr.push_back(cur_tok);
                    }
                }
            }


        public:

            /*
                store, msg, 10, +, 20, \n, print, msg, \n
                [store, KW], [msg, ID], [10, INT], [+, OP], [20, INT],
                [\n, EOF], [print, KW], [msg, ID], [\n, EOF]
            */

            std::vector<ExprAST> &AST;

            Parser(std::vector<lexer::Token> &toks, std::vector<ExprAST> &ast)
            : tokens(toks), AST(ast){}

            void parse(){
                adv();
                if (idx >= tokens.size())
                    return;

                if (cur_tok.type == TT_OP) {}

                else if (cur_tok.type == TT_ID) {}

                else if (cur_tok.type == TT_KW)
                    parse_kw();

                else if (cur_tok.type == TT_KW) {}

                parse();
            }
    };

}
