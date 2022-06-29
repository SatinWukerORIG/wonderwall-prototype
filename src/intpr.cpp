namespace intpr {

    void showlist(std::vector<lexer::Token> &vect){
        std::cout<<"[";
        for(auto it: vect){
            if (it.token == "\n")
                std::cout<<"'\\n'";
            else
                std::cout<<it.token<<", ";
        }
        std::cout<<"]\n";
    }

    void interpret(std::vector<parser::BaseNode*> &nodes) {
        // std::cout<<"node length: "<<nodes.size()<<std::endl;
        for(auto node: nodes) {
            if(auto it = dynamic_cast<parser::PrintNode*>(node)) {
                std::cout<<"PRINT ";
                showlist(it->expr);

                delete it;
            }
            else if(auto it = dynamic_cast<parser::StoreNode*>(node)) {
                std::cout<<"STORE "<<it->var_name<<" ";
                showlist(it->expr);

                delete it;
            }
        }
    }
}
