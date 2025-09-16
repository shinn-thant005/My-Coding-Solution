#include <iostream>
using namespace std;

int lcm(int, int, int);

int main() {
    int n1, n2, n3;
    int l;
    cin >> n1 >> n2 >> n3;
    l = lcm(n1, n2, n3);
    cout << "The LCM of " << n1 << " " << n2 << " " << n3 << ": " << l;
    return 0;
}

int lcm(int n1, int n2, int n3) {
    int m = 2;
    while (true) {
        if ((m % n1) == 0 && (m % n2) == 0 && (m % n3) == 0) {
            return m;
        }
        m++;
    }
    return 0;
}

