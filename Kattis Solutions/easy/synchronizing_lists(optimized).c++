// nicht
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (true) {
        int n;
        cin >> n;
        if (n == 0) break;

        vector<int> A(n), B(n);
        for (int i = 0; i < n; i++) cin >> A[i];
        for (int i = 0; i < n; i++) cin >> B[i];

        vector<int> sortedA = A;
        vector<int> sortedB = B;
        sort(sortedA.begin(), sortedA.end());
        sort(sortedB.begin(), sortedB.end());

        // Map: value in sortedA → value in sortedB
        unordered_map<int, int> match;
        match.reserve(n);
        for (int i = 0; i < n; i++) {
            match[sortedA[i]] = sortedB[i];
        }

        // Output B in the order of A
        for (int x : A) {
            cout << match[x] << "\n";
        }

        cout << "\n";  // Blank line between test cases
    }
    return 0;
}
