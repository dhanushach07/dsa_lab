
#include <iostream>
#include <string>
using namespace std;

struct Student
{
    string USN, Name, programme;
    int sem;
    long phNo;
    Student *next;
};

Student *head = nullptr;

void createSLL(int n)
{
    head = nullptr;

    for (int i = 0; i < n; i++)
    {
        Student  *  newnode = new Student;

        cout << "\nEnter Student details (USN, Name, Programme, Sem, PhNo): ";
        cin >> newnode->USN >> newnode->Name
            >> newnode->programme >> newnode->sem
            >> newnode->phNo;

        newnode->next = nullptr;

        if (head == nullptr)
            head = newnode;
        else
        {
            Student *temp = head;
            while (temp->next != nullptr)
                temp = temp->next;

            temp->next = newnode;
        }
    }

    cout << "\nStudent list created.\n";
}

void displaySLL()
{
    if (head == nullptr)
    {
        cout << "\nList is empty.\n";
        return;
    }

    Student *temp = head;
    cout << "\nLinked List:\n";

    while (temp != nullptr)
    {
        cout << temp->USN << "  "
             << temp->Name << "  "
             << temp->programme << "  "
             << temp->sem << "  "
             << temp->phNo << endl;

        temp = temp->next;
    }
}

void insertEnd()
{
    Student *newnode = new Student;

    cout << "\nEnter Student details (USN, Name, Programme, Sem, PhNo): ";
    cin >> newnode->USN >> newnode->Name
        >> newnode->programme >> newnode->sem
        >> newnode->phNo;

    newnode->next = nullptr;

    if (head == nullptr)
        head = newnode;
    else 
    {
        Student *temp = head;

        while (temp->next != nullptr)
            temp = temp->next;

        temp->next = newnode;
    }

    cout << "\nStudent inserted at end.\n";
}

void deleteEnd()
{
    if (head == nullptr)
    {
        cout << "\nList is empty.\n";
        return;
    }

    if (head->next == nullptr)
    {
        cout << "\nDeleted student: " << head->Name << endl;
        delete head;
        head = nullptr;
        return;
    }

    Student *temp = head;
    Student *prev = nullptr;
 
    while (temp->next != nullptr)
    {
        prev = temp;
        temp = temp->next;
    }

    cout << "\nDeleted student: " << temp->Name << endl;
    prev->next = nullptr;
    delete temp;
}

void insertFront()
{
    Student *newnode = new Student;

    cout << "\nEnter Student details (USN, Name, Programme, Sem, PhNo): ";
    cin >> newnode->USN >> newnode->Name
        >> newnode->programme >> newnode->sem
        >> newnode->phNo;

    newnode->next = head;
    head = newnode;

    cout << "\nStudent inserted at front.\n";
}

void deleteFront()
{
    if (head == nullptr)
    {
        cout << "\nList is empty.\n";
        return;
    }

    Student *temp = head;
    head = head->next;

    cout << "\nDeleted student: " << temp->Name << endl;
    delete temp;
}

int main()
{
    int choice, n;

    do
    {
        cout << "\n--- Menu ---\n";
        cout << "1. Create SLL of N students\n";
        cout << "2. Display SLL\n";
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
                cout << "Enter number of students: ";
                cin >> n;
                createSLL(n);
                break;

            case 2:
                displaySLL();
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
                cout << "\nExiting...\n";
                break;

            default:
                cout << "\nInvalid choice.\n";
        }

    } while (choice != 7);

    return 0;
}