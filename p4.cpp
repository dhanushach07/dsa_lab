#include <iostream>
#include <cstring>
using namespace std;

int F(char symbol) {
    switch (symbol) {
        case '+': case '-': return 2;
        case '*': case '/': case '%': return 4;
        case '^': return 5;
        case '(': return 0;
        case '#': return -1;
        default: return 8;
    }
}

int G(char symbol) {
    switch (symbol) {
        case '+': case '-': return 1;
        case '*': case '/': return 3;
        case '^': case '%': return 6;
        case '(': return 9;
        case ')': return 0;
        default: return 8;
    }
}

void infixToPostfix(const char infix[], char postfix[]) {
    char stack[30];
    int top = -1, j = 0;
    stack[++top] = '#';

    for (int i = 0; infix[i] != '\0'; i++) 
    {
        char symbol = infix[i];

        while (F(stack[top]) > G(symbol))
            postfix[j++] = stack[top--];

        if (F(stack[top]) != G(symbol))
            stack[++top] = symbol;
        else
            top--;
    }

    while (stack[top] != '#')
        postfix[j++] = stack[top--];

    postfix[j] = '\0';
}

int main() {
    char infix[30], postfix[30];
    cout << "Enter valid infix expression: ";
    cin.getline(infix, 30);

    infixToPostfix(infix, postfix);
    cout << "Given infix expression: " << infix << endl;
    cout << "Postfix expression: " << postfix << endl;
    return 0;
}