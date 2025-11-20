#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    int listNum = 1;

    while (cin >> N && N != 0) {
        cin.ignore();   // clear newline after integer input

        map<string, int> freq;  // auto-sorted by key

        for (int i = 0; i < N; i++) {
            string line;
            getline(cin, line);

            // Find the last word (species)
            int pos = line.find_last_of(' ');
            string species = line.substr(pos + 1);

            // Convert to lowercase
            for (char &c : species)
                c = tolower(c);

            // Count
            freq[species]++;
        }

        cout << "List " << listNum++ << ":\n";

        for (auto &p : freq) {
            cout << p.first << " | " << p.second << "\n";
        }
    }

    return 0;
}
