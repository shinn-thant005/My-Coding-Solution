#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t; 
    cin >> t; // number of test cases

    while (t--) {
        int n;
        cin >> n; // number of stores

        vector<int> positions(n);
        for (int i = 0; i < n; ++i) {
            cin >> positions[i];
        }

        // Sort the store positions
        sort(positions.begin(), positions.end());

        // The minimal distance Michael must walk
        // is twice the distance between the farthest stores
        int distance = 2 * (positions.back() - positions.front());

        cout << distance << endl;
    }

    return 0;
}
