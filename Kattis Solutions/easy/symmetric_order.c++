// OWN
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int n, count = 1;
    while (cin >> n && n != 0) {
        vector<string> name(n);
        int up = 0, down = n - 1;
        for (int i = 0; i < n; ++i) {
            string st;
            cin >> st;
            if (i % 2 == 0) name[up++] = st;
            else name[down--] = st;
        }

        cout << "SET " << count++ << endl;
        for (string &x : name)
            cout << x << endl;
    }
    return 0;
}
