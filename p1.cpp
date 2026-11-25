// Program 1 – Frequency Histogram Question: Design a C++ program to build a frequency histogram for data values in the range 1 to 10. Read and store data in an array, count the frequency of each value, and print the histogram. 

#include <iostream>
using namespace std;

int main() {
    const int MAX_VALUE = 10;
    int freq[MAX_VALUE + 1] = {0};
    int data[100], size;

    cout << "Enter no of data elements: ";
    cin >> size;
    cout << "Enter " << size << " numbers (between 1 and "<< MAX_VALUE << "):\n";

    for (int i = 0; i < size; i++) {
        cin >> data[i];
        if (data[i] >= 1 && data[i] <= MAX_VALUE)
            freq[data[i]]++;
    }

    cout << "\nHistogram:\n";
    for (int i = 1; i <= MAX_VALUE; i++) {
        if (freq[i] > 0) {
            cout << i << ": ";
            for (int j = 0; j < freq[i]; j++)
                cout << "*";
            cout << endl;  
        }
    }
    return 0;
}


// Output: Enter no of data elements: 5 Enter 5 numbers (between 1 and 10): 2 1 2 3 1  Histogram: 1: ** 2: ** 3: *