#include <iostream>
using namespace std;

int main() {
    int n;
    bool first = true;

    cout << "Enter a number ";
    cin >> n;
    for (int i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            if (!first) {
                cout << " * ";
            }
            cout << i;
            n /= i;
            first = false;
        }
    }
    if (n > 1) {
        if (!first) {
            cout << " * ";
        }
        cout << n;
    }
    return 0;
}
