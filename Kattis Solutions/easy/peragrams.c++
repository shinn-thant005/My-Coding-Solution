// nicht
#include <bits/stdc++.h>
using namespace std;

int main() {
    string line;
    cin >> line;

    int freq[26] = {0};
    for (char c : line) {
        freq[c - 'a']++;
    }

    int oddCount = 0;
    for (int i = 0; i < 26; i++) {
        if (freq[i] % 2 == 1) {
            oddCount++;
        }
    }

    int result = (oddCount <= 1)? 0 : (oddCount - 1);
    cout << result;
    return 0;
}
