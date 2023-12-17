#include <iostream>

class Stack {
private:
    float* array;
    int size;


public:
    int top;

    Stack(int n);

    Stack();

    Stack& operator<<(float value);

    float operator>>(float& value);

    Stack& operator=(const Stack& other);

    bool operator<(const Stack& other);

    bool operator==(const Stack& other);

    float operator[](int index);

    void pop();
};