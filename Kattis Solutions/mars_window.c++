#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int monthes = (n - 2018) * 12 + 8;
    if (monthes % 26 < 12) {
        cout << "yes";
    }
    else {
        cout << "no";
    }
    return 0;
}
