#include <bits/stdc++.h>
using namespace std;

bool isNameToken(const string& s) {
    // True if all characters are alphabetic
    for (char c : s) {
        if (!isalpha(c)) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string line;
    while (getline(cin, line)) {
        stringstream ss(line);
        string token;
        vector<string> nameParts;
        double sum = 0;
        int count = 0;

        while (ss >> token) {
            if (isNameToken(token)) {
                nameParts.push_back(token);
            } else {
                // Numeric token
                sum += stod(token);
                count++;
            }
        }

        double avg = sum / count;

        // Print average
        cout << fixed << setprecision(6) << avg << " ";

        // Print full name
        for (int i = 0; i < (int)nameParts.size(); i++) {
            if (i) cout << " ";
            cout << nameParts[i];
        }
        cout << "\n";
    }

    return 0;
}
