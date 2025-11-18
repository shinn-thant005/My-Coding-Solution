// OWN
// not optimized
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    while (cin >> n && n != 0) {
        vector<int> first(n);
        vector<int> second(n);

        for (int i = 0; i < n; i++) cin >> first[i];
        
        for (int i = 0; i < n; i++) cin >> second[i];
        
        vector<int> f2(first);
        vector<int> s2(n);

        sort(f2.begin(), f2.end());
        sort(second.begin(), second.end());

        for (int i = 0; i < n; i++) {
            auto it = find(first.begin(), first.end(), f2[i]); // using find is dangerous when duplicate elements exist,
            int index = it - first.begin();                    // since find() always find the first occurrence
            s2[index] = second[i];
        }

        for (int x : s2) {
            cout << x << "\n";
        }
        cout << "\n";
    }
    return 0;
}
