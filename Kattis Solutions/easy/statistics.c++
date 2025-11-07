// Own
#include <bits/stdc++.h>
using namespace std;

int main() {
    int count = 1;
    int n;
    while (cin >> n) {
        vector<int> arr(n);
        for(int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int max = *max_element(arr.begin(), arr.end());
        int min = *min_element(arr.begin(), arr.end());
        cout << "Case " << count << ": ";
        cout << min << " ";
        cout << max << " ";
        cout << (max - min) << endl;
        count++;
    }
    return 0;
}
