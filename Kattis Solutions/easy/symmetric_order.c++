#include <bits/stdc++.h>
using namespace std;

int main() {
    int count = 1;
    while (true) {
        int n;
        cin >> n;
        if (n == 0) {
            return 0;
        }
        vector<string> name(n);
        int up = 0;
        int down = n - 1;
        for (int i = 0; i < n; i++) {
            string st;
            cin >> st;
            if ((i + 1) % 2 != 0) {
                name[up] = st;
                up++;
            }
            else {
                name[down] = st;
                down--;
            }
        }

        cout << "SET " << count << endl;
        for (string x: name) {
            cout << x << endl;
        }
        count++;
    }
    return 0;
}
