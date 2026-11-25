

#include <iostream>
#include <string>
using namespace std;

struct Employee
{
    string ssn, name, dept, designation;
    float sal;
    long phNo;
    Employee *prev, *next;
};

Employee *head = nullptr, *rear = nullptr; //

Employee *createNode()
{
    Employee *newnode = new Employee;

    cout << "\nEnter Employee SSN: ";
    cin >> newnode->ssn;

    cout << "Enter Name: ";
    cin.ignore();
    getline(cin, newnode->name);

    cout << "Enter Department: ";
    getline(cin, newnode->dept);

    cout << "Enter Designation: ";
    getline(cin, newnode->designation);

    cout << "Enter Salary: ";
    cin >> newnode->sal;

    cout << "Enter Phone No: ";
    cin >> newnode->phNo;

    newnode->prev = nullptr;
    newnode->next = nullptr;

    return newnode;
}

void createDLL(int n)
{
    for (int i = 0; i < n; i++)
    {
        Employee *newnode = createNode();

        if (head == nullptr)
            head = rear = newnode;
        else
        {
            rear->next = newnode;
            newnode->prev = rear;
            rear = newnode;
        }
    }
}

void displayDLL()
{
    if (head == nullptr)
    {
        cout << "\nDLL is empty.\n";
        return;
    }

    Employee *temp = head;
    int count = 0;

    cout << "\n--- Employee List ---\n";

    while (temp != nullptr)
    {
        cout << "\nSSN: " << temp->ssn
             << "\nName: " << temp->name
             << "\nDept: " << temp->dept
             << "\nDesignation: " << temp->designation
             << "\nSalary: " << temp->sal
             << "\nPhone: " << temp->phNo << endl;

        temp = temp->next;
        count++;
    }

    cout << "\nTotal Employees: " << count << endl;
}

void insertEnd()
{
    Employee *newnode = createNode();

    if (head == nullptr)
        head = rear = newnode;
    else
    {
        rear->next = newnode;
        newnode->prev = rear;
        rear = newnode;
    }
}

void deleteEnd()
{
    if (rear == nullptr)
    {
        cout << "\nList is empty.\n";
        return;
    }

    Employee *temp = rear;

    if (head == rear)
        head = rear = nullptr;
    else
    {
        rear = rear->prev;
        rear->next = nullptr;
    }

    cout << "\nDeleted employee: " << temp->name << endl;
    delete temp;
}

void insertFront()
{
    Employee *newnode = createNode();

    if (head == nullptr)
        head = rear = newnode;
    else
    {
        newnode->next = head;
        head->prev = newnode;
        head = newnode;
    }
}

void deleteFront()
{
    if (head == nullptr)
    {
        cout << "\nList is empty.\n";
        return;
    }

    Employee *temp = head;

    if (head == rear)
        head = rear = nullptr;
    else
    {
        head = head->next;
        head->prev = nullptr;
    }

    cout << "\nDeleted employee: " << temp->name << endl;
    delete temp;
}

int main()
{
    int choice, n;

    while (true)
    {
        cout << "\n--- Menu ---\n";
        cout << "1. Create DLL of N employees\n";
        cout << "2. Display DLL and count nodes\n";
        cout << "3. Insert at end\n";
        cout << "4. Delete at end\n";
        cout << "5. Insert at front\n";
        cout << "6. Delete at front\n";
        cout << "7. Exit\n";

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "Enter number of employees: ";
                cin >> n;
                createDLL(n);
                break;

            case 2:
                displayDLL();
                break;

            case 3:
                insertEnd();
                break;

            case 4:
                deleteEnd();
                break;

            case 5:
                insertFront();
                break;

            case 6:
                deleteFront();
                break;

            case 7:
                cout << "\nExiting program.\n";
                return 0;

            default:
                cout << "\nInvalid choice. Try again.\n";
        }
    }

    return 0;
}

