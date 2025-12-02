// You are given a string containing only parentheses characters: '(', ')', '{', '}', '[', and ']'. 
// Your task is to check whether the parentheses are balanced or not.
// A string is considered balanced if:
// Every opening bracket has a corresponding closing bracket of the same type
// Brackets are closed in the correct order.
// | Operation | Complexity |
// | --------- | ---------- |
// | Time      | **O(n)**   |
// | Space     | **O(n)**   |

#include <iostream>
using namespace std;

#define MAX 100

class Stack {
    char arr[MAX];
    int top;

public:
    Stack() { top = -1; }

    bool isEmpty() { return top == -1; }
    bool isFull()  { return top == MAX - 1; }

    void push(char c) {
        if (isFull()) {
            cout << "Stack Overflow!\n";
            return;
        }
        arr[++top] = c;
    }

    char pop() {
        if (isEmpty()) {
            return '\0';   // return null char if empty
        }
        return arr[top--];
    }

    char peek() {
        if (isEmpty()) return '\0';
        return arr[top];
    }
};

bool isMatching(char open, char close) {
    if (open == '(' && close == ')') return true;
    if (open == '{' && close == '}') return true;
    if (open == '[' && close == ']') return true;
    return false;
}

bool isBalanced(string exp) {
    Stack s;

    for (int i = 0; i < exp.length(); i++) {
        char ch = exp[i];

        // if opening bracket, push
        if (ch == '(' || ch == '{' || ch == '[') {
            s.push(ch);
        }
        // if closing bracket
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (s.isEmpty()) return false;

            char top = s.pop();
            if (!isMatching(top, ch))
                return false;
        }
    }

    return s.isEmpty();
}

int main() {
    string exp;
    cout << "Enter parentheses string: ";
    cin >> exp;

    if (isBalanced(exp))
        cout << "Balanced\n";
    else
        cout << "Not Balanced\n";

    return 0;
}
