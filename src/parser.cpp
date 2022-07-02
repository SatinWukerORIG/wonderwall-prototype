namespace parser {

    class BaseNode{
        public:
            virtual ~BaseNode() {};

    };

    class PrintNode : public BaseNode{
        public:
            std::vector<lexer::Token> expr;
            PrintNode(std::vector<lexer::Token> expr)
            : expr(expr) {}

    };

    class StoreNode : public BaseNode{
        public:
            std::string var_name;
            std::vector<lexer::Token> expr {};
            StoreNode(std::string var_name, std::vector<lexer::Token> expr)
            : var_name(var_name), expr(expr) {}
    };

    class Parser {
        private:
            int idx = 0;
            std::vector<lexer::Token> *tokens = new std::vector<lexer::Token>();

            void parse() {
                if (tokens->at(idx).token == "print") {
                    /*  print_node
                            |
                            expr    */
                    std::vector<lexer::Token> list {};
                    while(tokens->at(idx).type == TT_EOF) {
                        list.push_back(tokens->at(idx));
                    }
                    AST->push_back(new PrintNode(list));
                }

                else if (tokens->at(idx).token == "store") {
                    /* store_node
                        /    \
                        name   expr */
                    // std::cout<<"debug: store\n";
                    std::vector<lexer::Token> list {};
                    while(tokens->at(idx).type == TT_EOF) {
                        list.push_back(tokens->at(idx));
                    }
                    AST->push_back(new StoreNode(tokens->at(idx).token, list));
                }

                else if (tokens->at(idx).token == "if") {
                    /*
                            if_node
                            /   |   \
                        cond  stmts else
                    */
                    
                }
                idx++;
            }

        public:
            std::vector<BaseNode*> *AST = new std::vector<BaseNode*>();

            Parser(std::vector<lexer::Token> *tokens,
                std::vector<BaseNode*> *AST)
            : tokens(tokens), AST(AST)
            {
                while (idx < tokens->size()) {
                    parse();
                }
            }

    };

}
