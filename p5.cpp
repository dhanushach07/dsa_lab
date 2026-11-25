#include <iostream>
#include <cmath>
#include <cctype>

using namespace std;

int stack[20];
int top = -1;

void push(int item) {
    stack[++top] = item;
}

int pop() {
    return stack[top--];
}

int main() {
    char postfix[30];
    cout << "Enter valid postfix expression: ";
    cin >> postfix;

    for (int i = 0; postfix[i] != '\0'; i++) {
        char symb = postfix[i];

        if (isdigit(symb))
            push(symb - '0');
        else {
            int op2 = pop();
            int op1 = pop();
            int res = 0;

            switch (symb) {
                case '+': res = op1 + op2; break;
                case '-': res = op1 - op2; break;
                case '*': res = op1 * op2; break;
                case '/': res = op1 / op2; break;
                case '%': res = op1 % op2; break;
                case '^': res = (int)pow(op1, op2); break;
            }
            push(res);
        }
    }

    cout << "Result = " << pop() << endl;
    return 0;
}

