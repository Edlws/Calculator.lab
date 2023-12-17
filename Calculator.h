#include "string"
#include "Stack.h"
#include "cmath"

class Calculator {

private:
    std::string expression;

    int numLength(const std::string& str, int num);

    bool validBrackets(const std::string& expression);

    bool isOperator(char ch);

    bool validOperators(const std::string& expression);

    int getPriority(char ch);

    float applyOperator(float op1, float op2, int op);

public:

    Calculator();

    void setExp(std::string str);

    float Calculate();
};
