#include "Stack.h"

Stack::Stack(int n) {
    size = n;
    top=-1;
    array = new float[size];
}
Stack::Stack() {
    size = 1;
    top=-1;
    array = new float[size];
}

Stack& Stack::operator<<(float value) {
    if (top < size - 1) {
        array[++top] = value;
        return *this;
    }
    if (top >= size - 1) {
        float* tempArray = new float[size+1];
        for (int i=0; i < size; i++){
            tempArray[i] = array[i];
        }
        size+=1;
        array[++top] = value;
    }
    return *this;
}

float Stack::operator>>(float& value) {
    if (top >= 0) {
        value = array[top--];
    } else {
        throw std::out_of_range("Stack is empty");
    }
    return value;
}

Stack& Stack::operator=(const Stack& other) {
    if (this != &other) {
        size = other.size;
        top = other.top;
        delete[] array;
        array = new float[size];
        for (int i = 0; i <= top; ++i) {
            array[i] = other.array[i];
        }
    }
    return *this;
}

bool Stack::operator<(const Stack& other) {
    return top < other.top;
}

bool Stack::operator==(const Stack& other) {
    if (top != other.top) {
        return false;
    }
    for (int i = 0; i <= top; ++i) {
        if (array[i] != other.array[i]) {
            return 0;
        }
    }
    return true;
}

float Stack::operator[](int index) {
    if (index >= 0 && index <= top) {
        return array[index];
    } else {
        throw std::out_of_range("Out of bounds");
    }
}

void Stack::pop() {
    if (top >= 0) {
        top--;
    } else {
        throw std::out_of_range("Stack is empty");
    }
}