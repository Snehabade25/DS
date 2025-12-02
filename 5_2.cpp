// Convert given infix expression Eg. a-b*c-d/e+f into postfix form using stack and show the operations step by step.
// Time Complexity	    O(n)
// Space Complexity	    O(n)

#include <iostream>
using namespace std;

class Stack {
    char arr[50];
    int top;

public:
    Stack() {
        top = -1;
    }

    void push(char x) {
        arr[++top] = x;
    }

    char pop() {
        return arr[top--];
    }

    char peek() {
        return arr[top];
    }

    bool isEmpty() {
        return top == -1;
    }
};

int precedence(char op) {
    if (op == '*' || op == '/')
        return 2;
    if (op == '+' || op == '-')
        return 1;
    return 0;
}

bool isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

string infixToPostfix(string infix) {
    Stack s;
    string postfix = "";

    for (int i = 0; i < infix.length(); i++) {
        char ch = infix[i];

        // If operand → add to output
        if (isalnum(ch)) {
            postfix += ch;
        }
        // Operator handling
        else if (isOperator(ch)) {
            while (!s.isEmpty() && precedence(s.peek()) >= precedence(ch)) {
                postfix += s.pop();
            }
            s.push(ch);
        }
    }

    // Pop remaining operators
    while (!s.isEmpty()) {
        postfix += s.pop();
    }

    return postfix;
}

int main() {
    string infix;
    cout << "Enter infix expression: ";
    cin >> infix;

    string postfix = infixToPostfix(infix);

    cout << "\nPostfix Expression: " << postfix << endl;

    return 0;
}
