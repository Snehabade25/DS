// You are given a postfix expression (also known as Reverse Polish Notation) consisting of single-digit operands and 
// binary operators (+, -, *, /). Your task is to evaluate the expression using stack and return its result.
// Time = O(n)
// Space = O(n)

#include <iostream>
using namespace std;

#define MAX 100

class Stack {
    int arr[MAX];
    int top;

public:
    Stack() { top = -1; }

    bool isEmpty() { return top == -1; }
    bool isFull()  { return top == MAX - 1; }

    void push(int x) {
        if (isFull()) {
            cout << "Stack Overflow\n";
            return;
        }
        arr[++top] = x;
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack Underflow\n";
            return -1;
        }
        return arr[top--];
    }
};

// Function to evaluate postfix expression
int evaluatePostfix(string exp) {
    Stack s;

    for (int i = 0; i < exp.length(); i++) {

        char ch = exp[i];

        // If operand, push to stack
        if (isdigit(ch)) {
            s.push(ch - '0');  // convert char to int
        }
        else {
            // Operator: pop two operands
            int val2 = s.pop();
            int val1 = s.pop();
            int result;

            switch(ch) {
                case '+': result = val1 + val2; break;
                case '-': result = val1 - val2; break;
                case '*': result = val1 * val2; break;
                case '/': result = val1 / val2; break;
                default : result = 0;
            }
            s.push(result);
        }
    }

    return s.pop();
}

int main() {
    string exp;
    cout << "Enter postfix expression: ";
    cin >> exp;

    cout << "Result = " << evaluatePostfix(exp) << endl;

    return 0;
}
