#include "wonderwall.h"

namespace ast{
    class ExprAST{
        public:
        virtual ~ExprAST() = default;
    };

    class NumExprNode : public ExprAST{
        double value;
        public: NumExprNode(double value): value(value) {}
    };

    class VariableExprNode : public ExprAST {
        std::string Name;
        public:
        VariableExprNode(const std::string &Name) : Name(Name) {}
    };
}