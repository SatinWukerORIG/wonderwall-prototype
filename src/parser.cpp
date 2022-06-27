#include<vector>  // std::vector<>
#include<string>  // std::string
#include<memory>  // std::unique_ptr<> std::shared_ptr
#include "error.cpp"


namespace parser {

    class BaseNode{
        public:
            virtual ~BaseNode() {};
    };

    class PrintNode : public BaseNode{
        std::vector<lexer::Token> expr;

        public:
            const std::string name = "print";
            PrintNode(std::vector<lexer::Token> expr)
            : expr(expr) {}

    };

    class StoreNode : public BaseNode{
        public:
            const std::string name = "store";
            const std::string &var_name;
            const std::vector<lexer::Token> &expr;
            StoreNode(std::string &var_name, const std::vector<lexer::Token> &expr)
            : var_name(var_name), expr(expr) {}
    };

    void insert_node(std::vector<BaseNode*> &branch, BaseNode* node){
        /*
            branch
              |
             node
        */
        branch.push_back(node);
    }

    class Parser {
        private:
            int idx;
            std::vector<std::vector<lexer::Token>> &tokens;

        public:

            std::vector<BaseNode*> &AST;

            Parser(std::vector<std::vector<lexer::Token>> &tokens, std::vector<BaseNode*> &AST)
            : tokens(tokens), AST(AST)
            {
                while (idx < tokens.size()) {
                    if (tokens[idx][0].token == "print") {
                        /*  print_node
                                |
                               expr    */
                        std::vector<lexer::Token> expr {tokens[idx][1], tokens[idx].back()};
                        BaseNode *printnode = new PrintNode(expr);
                        insert_node(AST, printnode);
                    }

                    else if (tokens[idx][0].token == "store") {
                        /* store_node
                            /    \
                          name   expr */
                        std::vector<lexer::Token> expr {tokens[idx][2], tokens[idx].back()};
                        BaseNode *storenode = new StoreNode(tokens[idx][1].token, expr);
                        insert_node(AST, storenode);
                    }

                    else if (tokens[idx][0].token == "if") {
                        /*
                              if_node
                            /    |    \
                            cond stmts else
                        */
                    }
                    idx++;
                }
            }

    };

}
