// Program 2 – Pattern Replacement in a String Question: Write a C++ program to replace all occurrences of  a pattern string in a main string with a replacement string. 

#include <iostream>
#include <cstring>
using namespace std;

int length(const char str[]) {
    int i = 0;
    while (str[i] != '\0')
        i++;
    return i;
}

bool match(const char str[], const char pat[], int pos) {
    int i=0;
   while(pat[i] != '\0') 
    {
        if (str[pos + i] != pat[i])
            return false;
        i++;
    }
    return true;
}

int main() {
    char str[100], pat[100], rep[100], result[200];
    cout << "Enter main string: ";
    cin.getline(str, 100);
    cout << "Enter pattern string: ";
    cin.getline(pat, 100);
    cout << "Enter replacement string: ";
    cin.getline(rep, 100);

    int lenStr = length(str), lenPat = length(pat);
    int lenRep = length(rep), i = 0, k = 0;
    bool found = false;

    while (i < lenStr)
    {
        if (i <= lenStr - lenPat && match(str, pat, i)) 
        {
            for (int j = 0; j < lenRep; j++)
                result[k++] = rep[j];
            i += lenPat;
            found = true;
        } 
        else
        {
            result[k++] = str[i++];
        }
    }
    result[k] = '\0';

    if (!found)
        cout << "Pattern not found" << endl;
    else {
        cout << "All occurrences replaced" << endl;
        cout << "Result: " << result << endl;
    }
    return 0;
}

