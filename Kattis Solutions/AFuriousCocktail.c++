#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, T;
    cin >> n >> T;
    int t[n];
    for (int i = 0; i < n; i++) {
        cin >> t[i];
    }
    
    sort(t, t + n, greater<int>());
    
    if (t[0] > T*2) cout << "YES";
    else cout << "NO";
    return 0;
}
