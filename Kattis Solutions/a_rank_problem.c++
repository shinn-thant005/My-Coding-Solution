#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, g;
    char T;
    cin >> t >> g;
    vector<int> arr(t);

    // build an array of teams in initial order (1 = first, 2 = second).
    for (int i = 0; i < t; i++) {
        arr[i] = i + 1;
    }

    for (int i = 0; i < g; i++) {
        int a,b;
        int i1, i2;
        cin >> T >> a >> T >> b;

        auto c = find(begin(arr), end(arr), a);
        auto d = find(begin(arr), end(arr), b);

        i1 = distance(begin(arr), c);
        i2 = distance(begin(arr), d);

        /*
        if the winning team is ranked lower than the losing team, 
        move the losing team under the winning team, which means moving all the teams starting from winning team
        forward by one index and place the losing team just behind the winning team.
        */
        if (i1 > i2) {
            int diff = i1 - i2;
            int temp = arr[i2];
            for (int j = i2; j < i1; j++) {
                arr[j] = arr[j + 1];
            }
            arr[i1] = temp;
        }
    }
    for (int i = 0;  i < t; i ++) {
        cout << "T" << arr[i] << " ";
    }
    return 0;
}
