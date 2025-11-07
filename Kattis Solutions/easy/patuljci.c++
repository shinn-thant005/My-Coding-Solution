// Own
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> arr(9);
    int total = 0;
    for (int i = 0; i < 9; i++) {
        cin >> arr[i];
        total += arr[i];
    }

    int target = total - 100;
    int impo1 = -1, impo2 = -1;

    for (int i = 0; i < 9 && impo1 == -1; i++) {
        for (int j = i + 1; j < 9; j++) {
            if (arr[i] + arr[j] == target) {
                impo1 = i;
                impo2 = j;
                break;
            }
        }
    }

    for (int i = 0; i < 9; i++) {
        if (i == impo1 || i == impo2) continue;
        cout << arr[i] << '\n';
    }

    return 0;
}
