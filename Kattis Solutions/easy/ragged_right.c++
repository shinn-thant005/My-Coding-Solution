// OWN
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int>linesLen;
    string line;
    int result = 0;
    while (getline(cin, line)) {
        linesLen.push_back(line.length());
    }

    int maxLength = *max_element(linesLen.begin(), linesLen.end());
    for (int i = 0; i < linesLen.size()- 1; i++) {
        if (linesLen[i] == maxLength) continue;
        int diff = maxLength - linesLen[i];
            result += 1LL * diff * diff;    // it promotes all operands to long long before multiplying 
                                            // and preventing overflow.
    }
    cout << result;

    
    return 0;
}
