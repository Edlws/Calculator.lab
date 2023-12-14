#include <iostream>

class Stack {
private:
    int* array;
    int size;
    int top;

public:
    Stack(int n);

    Stack& operator<<(int value);

    void operator>>(int& value);

    Stack& operator=(const Stack& other);

    bool operator<(const Stack& other);

    bool operator==(const Stack& other);

    int operator[](int index);
};
