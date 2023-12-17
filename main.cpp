#include "Calculator.h"

int main() {
    std::string str;
    std::cout << "Enter the expression: ";
    std::cin >> str;
    Calculator calculator;
    calculator.setExp(str);
    std::cout << calculator.Calculate();
    return 0;
}