// Nicht
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    int diff = abs(a - b);
    int answer = min(diff, 360 - diff);

    cout << answer << endl;
    return 0;
}
