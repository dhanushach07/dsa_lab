#include <iostream>
using namespace std;

struct Rec
{
    int key;
    string name;
    bool used = false;
};

int main()
{
    int m, n;

    cout << "Enter table size m: ";
    cin >> m;

    Rec HT[100];

    cout << "Enter no of records n: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int k;
        string name;

        cout << "\nKey: ";
        cin >> k;

        cout << "Name: ";
        cin >> name;

        int index = k % m; //adress

        while (HT[index].used)
        {
            index = (index + 1) % m;
        }

        HT[index].key = k;
        HT[index].name = name;
        HT[index].used = true;

        cout << "Stored at index " << index << endl;
    }

    // Display hash table
    cout << "\nHash table:\n";

    for (int i = 0; i < m; i++)
    {
        if (HT[i].used)
            cout << i << ": " << HT[i].key
                 << " -> " << HT[i].name << endl;
        else
            cout << i << ": Empty\n";
    }

    // Search
    int s;
    cout << "\nSearch key: ";
    cin >> s;

    int index = s % m;
    int start = index;

    while (HT[index].used)
    {
        if (HT[index].key == s)
        {
            cout << "Found at index " << index
                 << ": " << HT[index].name << endl;
            return 0;
        }

        index = (index + 1) % m;

        if (index == start)
            break;
    }

    cout << "Not found\n";

    return 0;
} 