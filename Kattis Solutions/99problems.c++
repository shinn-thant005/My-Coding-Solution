#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int left = n, right = n;

    while (left % 100 != 99 && right % 100 != 99) {
        if (left > 1) { // a condition to make sure the left doesn't go all the way to negative numbers.
            left--;
        }
        right++;
    } 

    if (left % 100 == 99 && right % 100 == 99) {
        cout << right;
    }
    else if (right % 100 == 99) {
        cout << right;
    }
    else {
        cout << left;
    }
    return 0;
}
