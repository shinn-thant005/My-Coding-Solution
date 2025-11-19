// OWN
#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    while(T--) {
        string message;
        cin >> message;
        int L = message.length();
        int M = 0;
        int t = 1;

        while(true) {
            M = t * t;
            if (M >= L) break;
            t++;
        }

        int asterik = M - L; // find the number of asterik to add
        char arr[t][t];         // build an array of t x t size

        for (int i = 0; i < asterik; i++) {
            message += '*';
        }

        int k = 0;
        for (int i = 0; i < t; i++) {
            for (int j = 0; j < t; j++) {
                arr[i][j] = message[k];
                k++;
            }
        }

        for (int i = 0; i < t; i++) {
            for (int j = t - 1; j >= 0; j--) {
                if (arr[i][j] == '*') continue;
                cout << arr[j][i];
            }
        }
        cout << endl;
    }
    return 0;
}
