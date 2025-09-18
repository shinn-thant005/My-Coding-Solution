#include <iostream>
using namespace std;

int main() {
    int n;
    char choice;

    do {
        cin >> n;
        int total = 0;

        if (n <= 1) {
            cout << n << " is not a perfect number.";
            cout << "\nDo you wish to continue (y/n)? ";
            cin >> choice;
            continue;
        }
    
        for (int i = 1; i < n; i++) {
            if (n % i == 0) {
                total += i;
            }
        }
        if (total == n) {
            cout << n << " is a perfect number.";
        }
        else {
            cout << n << " is not a perfect number";
        }

        cout << "\nDo you wish to continue (y/n)? ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');
    
    return 0;
}
