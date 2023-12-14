#include "Stack.h"

Stack::Stack(int n) {
    size = n;
    top=-1;
    array = new int[size];
}

Stack& Stack::operator<<(int value) {
    if (top < size - 1) {
        array[++top] = value;
    }
    if (top >= size - 1) {
        int* tempArray = new int[size+1];
        for (int i=0; i < size; i++){
            tempArray[i] = array[i];
        }
        size+=1;
        array[++top] = value;
    }
    return *this;
}

void Stack::operator>>(int& value) {
    if (top >= 0) {
        value = array[top--];
    } else {
        std::cout << "Stack is empty" << std::endl;
    }
}

Stack& Stack::operator=(const Stack& other) {
    if (this != &other) {
        size = other.size;
        top = other.top;
        delete[] array;
        array = new int[size];
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

int Stack::operator[](int index) {
    if (index >= 0 && index <= top) {
        return array[index];
    } else {
        std:: cout << "Out of bounds" << std::endl;
        return -249824;
    }
}