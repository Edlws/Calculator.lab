#include "Calculator.h"

int Calculator::numLength(const std::string& str, int num) {
    int count = 1;

    if (str.size() > 1) {
        while (num < str.size() - 1 && isdigit(str[num + 1])) {
            count++;
            num++;
        }
    }

    return count;
}

bool Calculator::validBrackets(const std::string& expression) {
    int count = 0;
    for (char ch : expression) {
        if (ch == '(') {
            count++;
        } else if (ch == ')') {
            count--;
        }
    }
    if (count != 0) {
        return false;
    } else {
        return true;
    }
}

bool Calculator::isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

bool Calculator::validOperators(const std::string& expression) {
    int count = 0;
    for (char ch : expression) {
        if (isdigit(ch)) {
            count++;
        }
        if (isOperator(ch)) {
            count--;
        }
    }
    if (count >= 1){
        return true;
    }
    return false;
}

int Calculator::getPriority(char ch) {
    if (ch == '+' || ch == '-') {
        return 1;
    } else if (ch == '*' || ch == '/') {
        return 2;
    }
    return 0;
}

float Calculator::applyOperator(float op1, float op2, int op) {
    switch (op) {
        case '+':
            return op1 + op2;
        case '-':
            return op1 - op2;
        case '*':
            return op1 * op2;
        case '/':
            if (op2 != 0) {
                return op1 / op2;
            } else {
                throw std::invalid_argument("Division by zero");
            }
    }
}

Calculator::Calculator(){
};

void Calculator::setExp(std::string str){
    this->expression = str;
}

float Calculator::Calculate() {
    Stack operands;
    Stack operators;
    std::string expr = this->expression;

    if (validBrackets(expr) && validOperators(expr)) {
        for (int i = 0; i < expr.size(); i++) {
            if (isdigit(expr[i])) {
                int count = numLength(expr, i);
                if (count > 1) {
                    int value = 0;
                    int counter = 0;
                    while (count > 0) {
                        value += pow(10, count - 1) * (expr[i + counter] - '0');
                        count--;
                        counter++;
                    }
                    i += counter - 1;
                    operands << value;
                } else {
                    operands << (expr[i] - '0');
                }
            } else {
                if (isOperator(expr[i])) {
                    while (operators.top > -1 && getPriority(operators[operators.top]) >= getPriority(expr[i])) {
                        float op2;
                        operands >> op2;
                        float op1;
                        operands >> op1;
                        operands << applyOperator(op1, op2, operators[operators.top]);
                        operators.pop();
                    }
                    operators << expr[i];
                } else {
                    switch (expr[i]) {
                        case '(':
                            operators << expr[i];
                            break;
                        case ')':
                            while (operators.top > -1 && operators[operators.top] != '(') {
                                float op2;
                                operands >> op2;
                                float op1;
                                operands >> op1;
                                float op;
                                operators >> op;
                                operands << applyOperator(op1, op2, op);
                            }
                            operators.pop();
                            break;
                    }
                }
            }
        }

        while (operators.top > -1) {
            float op2;
            operands >> op2;
            float op1;
            operands >> op1;
            float op;
            operators >> op;
            operands << applyOperator(op1, op2, op);
        }

        return operands[operands.top];
    } else {
        throw std::invalid_argument("Invalid expression");
    }
}
