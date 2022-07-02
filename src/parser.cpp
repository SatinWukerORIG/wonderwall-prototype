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
            std::vector<std::vector<lexer::Token>> *tokens = new std::vector<std::vector<lexer::Token>>();

            inline void parse() {
                if (tokens->at(idx)[0].token == "print") {
                    /*  print_node
                            |
                            expr    */
                    // std::cout<<"debug: print\n";
                    AST->push_back(new PrintNode(
                        {tokens->at(idx)[1], tokens->at(idx).back()}));
                }

                else if (tokens->at(idx)[0].token == "store") {
                    /* store_node
                        /    \
                        name   expr */
                    // std::cout<<"debug: store\n";
                    AST->push_back(new StoreNode(tokens->at(idx)[1].token,
                        {tokens->at(idx)[2], tokens->at(idx).back()}));
                }

                else if (tokens->at(idx)[0].token == "if") {
                    /*
                            if_node
                            /   |    \
                        cond stmts else
                    */
                    
                }
                idx++;
            }

        public:
            std::vector<BaseNode*> *AST = new std::vector<BaseNode*>();

            Parser(std::vector<std::vector<lexer::Token>> *tokens,
                std::vector<BaseNode*> *AST)
            : tokens(tokens), AST(AST)
            {
                while (idx < tokens->size()) {
                    parse();
                }
            }

    };

}
