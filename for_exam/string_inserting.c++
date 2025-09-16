#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char string1[100];
    char string2[100];
    int n;

    cout << "Enter a string 1: ";
    cin.getline(string1, 100);

    cout << "Enter a string 2: ";
    cin.getline(string2, 100);

    strcat(string2, " ");
    cout << "Enter the position to put: ";
    cin >> n;

    int len1 = strlen(string1);
    int len2 = strlen(string2);

    for (int i = len1; i >= n; i--) {
        string1[i + len2] = string1[i];
    }


    for (int i = 0; i < len2; i++) {
        string1[n + i] = string2[i];
    }

    cout << "The result string is: " << string1 << endl;
    return 0;
}
