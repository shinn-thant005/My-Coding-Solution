#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, P;
    cin >> N >> P;
    
    vector<int> students(N);
    for (int i = 0; i < N; ++i) {
        cin >> students[i];
        students[i] -= P;  // Convert to profit per break
    }

    // Kadane’s algorithm
    int maxProfit = 0, current = 0;
    for (int x : students) {
        current = max(0, current + x);
        maxProfit = max(maxProfit, current);
    }

    cout << maxProfit << endl;
    return 0;
}
