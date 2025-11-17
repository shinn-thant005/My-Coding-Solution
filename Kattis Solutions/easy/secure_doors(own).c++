#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    set<string> in;
    set<string> out;
    bool first = true;
    while (n--) {
        string tracking, name;
        cin >> tracking >> name;
        
        if (tracking[1] == 'n') {
            cout << name << " entered";
            if(in.find(name) != in.end()) {
                cout << " (ANOMALY)";
            }
            if (out.find(name) != out.end()) {
                out.erase(name);
            }
            in.insert(name);
        }
        else {
            cout << name << " exited";
            if (out.find(name) != out.end() || in.find(name) == in.end()) {
                cout << " (ANOMALY)";
            }
            if (in.find(name) != in.end()) {
                in.erase(name);
            }
            out.insert(name);
        }
        cout << "\n";
    }
    return 0;
}
