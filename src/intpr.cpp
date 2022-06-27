namespace intpr {

    void interpret(std::vector<parser::BaseNode*> &nodes) {

        for(auto node: nodes) {
            if(auto it = dynamic_cast<parser::PrintNode*>(node)) {
                std::cout<<it->name<<"\n";
                delete it;
            }
            else if(auto it = dynamic_cast<parser::StoreNode*>(node)) {
                std::cout<<it->name<<"\n";
                delete it;
            }
        }
    }
}