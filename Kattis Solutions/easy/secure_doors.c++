// Nicht
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    unordered_set<string> inside;   // tracks who is currently inside

    while (n--) {
        string action, name;
        cin >> action >> name;

        bool anomaly = false;

        if (action == "entry") {
            if (inside.count(name)) {
                anomaly = true;
            } else {
                inside.insert(name);
            }
            cout << name << " entered";
        }
        else { // exit
            if (!inside.count(name)) {
                anomaly = true;
            } else {
                inside.erase(name);
            }
            cout << name << " exited";
        }

        if (anomaly) cout << " (ANOMALY)";
        cout << "\n";
    }

    return 0;
}
