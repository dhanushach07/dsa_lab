#include <iostream>
#include <cstring>
using namespace std;

#define MAX 5

class Stack {
    int arr[MAX];
    int top;

public:
    Stack()
     {
      top = -1; 
    }

    void push(int element) {
        if (top >= MAX - 1)
            cout << "Stack overflow! Cannot push element\n";
        else {
            arr[++top] = element;
            cout << element << " is pushed into stack\n";
        }
    }

    int pop() {
        if (top == -1) {
            cout << "Stack empty, cannot pop\n";
            return -1;
        } else {
            int popped = arr[top--];
            cout << popped << " popped from stack\n";
            return popped;
        }
    }

    void display() {
        if (top == -1)
            cout << "Stack empty\n";
        else {
            cout << "Stack contents (top to bottom): ";
            for (int i = top; i >= 0; i--)
                cout << arr[i] << " ";
            cout << endl;
        }
    }

    void checkOverflow() {
        top = MAX - 1;
        cout << "Filling stack to max capacity...\n";
        push(100);
    }

    void checkUnderflow() {
        top = -1;
        cout << "Emptying stack...\n";
        pop();
    }

    void checkPalindrome(string str) {
        int len = str.length();
        char temp[MAX * 20];
        int t = -1;
 
        for (int i = 0; i < len; i++)
            temp[++t] = str[i];

        bool palindrome = true;
        for (int i = 0; i < len; i++) {
            if (temp[t--] != str[i]) {
                palindrome = false;
                break;
            }
        }

        if (palindrome)
            cout << str << " is palindrome\n";
        else
            cout << str << " is NOT a palindrome\n";
    }
};

int main() {
    Stack s;
    int choice, element;
    string input;

    do {
        cout << "\n--- Stack Menu ---\n";
        cout << "1. Push an element into stack\n";
        cout << "2. Pop an element\n";
        cout << "3. Check string palindrome\n";
        cout << "4. Demonstrate overflow and underflow\n";
        cout << "5. Display stack status\n";
        cout << "6. Exit\n";
        cout << "Enter your choice (1-6): ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter integer to push: ";
            cin >> element;
            s.push(element);
            break;
        case 2:
            s.pop();
            break;
        case 3:
            cout << "Enter string to check: ";
            cin >> input;
            s.checkPalindrome(input);
            break;
        case 4:
            s.checkOverflow();
            s.checkUnderflow();
            break;
        case 5:
            s.display();
            break;
        case 6:
            break;
        default:
            cout << "Invalid choice! Choose from 1 to 6\n";
        }
    } while (choice != 6);
    return 0;
}