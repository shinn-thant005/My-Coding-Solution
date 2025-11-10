// OWN
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> days(n);
    for (int i = 0; i < n; i++) {
        cin >> days[i];
    }

    sort(days.rbegin(), days.rend());

    int max_day = 0;
    for (int i = 0; i < n; i++) {
        int grown_day = days[i] + i + 1;
        max_day = max(max_day, grown_day);
    }

    cout << max_day + 1 << endl;
    return 0;
}
