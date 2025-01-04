#include <iostream>
#include <string>
using namespace std;

// 20. Valid Parentheses

class Stack {
private:
    char *arr;          
    int top;      
    int capacity;      

public:
    Stack(int size) {
        arr = new char[size];
        capacity = size;
        top = -1;
    }

    ~Stack() {
        delete[] arr;
    }
    void push(char x) {
        arr[++top] = x;
    }

    char pop() {
        return arr[top--];
    }

    char peek() const {
        return arr[top];
    }
};

bool isValid(string s) {
    int open_parentheses = 0;

    Stack mode = Stack(s.length());

    for (size_t i = 0; i < s.length(); i++) {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
            open_parentheses++;
            mode.push(s[i]);
        } else if (s[i] == ')' || s[i] == '}' || s[i] == ']') {
            if (open_parentheses == 0) {
                return false;
            } else if (mode.peek() == '(' && s[i] == ')') {
                mode.pop();
                open_parentheses--;
                continue;
            } else if (mode.peek() == '{' && s[i] == '}') {
                mode.pop();
                open_parentheses--;
                continue;
            } else if (mode.peek() == '[' && s[i] == ']') {
                mode.pop();
                open_parentheses--;
                continue;
            } else {
                return false;
            }
        }
    }


    return open_parentheses == 0;
}

int main() {
    string check = "(]";

    cout << isValid(check) << endl;
}