#include<vector>  // std::vector<>
#include<string>  // std::string
#include<memory>  // std::unique_ptr<>
#include<stdexcept>

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
            lexer::Token cur_tok;              // current token
            lexer::Lexer &lexer;

            void adv() {
                try {
                    cur_tok = lexer.get_tok();
                }
                catch(std::out_of_range) {
                    exit (EXIT_FAILURE);
                }
            }

            std::vector<lexer::Token> parse_expr(){
                std::vector<lexer::Token> expr;
                while(cur_tok.type != TT_EOF){
                    adv();
                    std::cout<<cur_tok.token<<" ";
                    expr.push_back(cur_tok);
                }
                return expr;
            }

            void parse_kw()
            {
                if (cur_tok.token == "print") {
                    /*  print_node
                            |
                           expr    */
                    std::cout<<"print: ";
                    parse_expr();
                    // PrintNode(parse_expr());
                }

                else if (cur_tok.token == "store") {
                    /*  store_node
                          /    \
                        name   expr */
                    std::cout<<"store: ";
                    adv();
                    parse_expr();
                    // StoreNode(parse_expr());
                }

                else if (cur_tok.token == "if") {
                    /*  if_node
                         /  \
                      cond  child_stmts */
                    std::vector<lexer::Token> child_stmts;
                    int if_count;
                    while (if_count != 0){
                        adv();
                        if (cur_tok.token == "if") if_count++;
                        else if (cur_tok.token == "end") if_count--;
                        child_stmts.push_back(cur_tok);
                    }
                    std::cout<<"if: ";
                    parse_expr();
                }
            }


        public:

            /*
                store, msg, 10, +, 20, \n, print, msg, \n
                [store, KW], [msg, ID], [10, INT], [+, OP], [20, INT],
                [\n, EOF], [print, KW], [msg, ID], [\n, EOF]
            */

            std::vector<ExprAST> &AST;

            Parser(lexer::Lexer &lex, std::vector<ExprAST> &ast)
            : lexer(lex), AST(ast){}
            int time = 0;
            void parse(){
                adv();

                if (cur_tok.type == TT_OP) {}

                else if (cur_tok.type == TT_ID) {}

                else if (cur_tok.type == TT_KW)
                    parse_kw();

                else if (cur_tok.type == TT_KW) {}

                parse();
            }
    };

}
