#include <iostream>
using namespace std;
#include <algorithm>


int main() {
    char repeat;
    do {
        int arr[10];
        for (int i = 0; i < 10; i++) {
            cin >> arr[i];
        }
    
        sort(arr, arr + 10);
    
        cout << "Sorted Array: ";
        for (int i = 0; i < 10; i++) {
            cout << arr[i] << " ";
        }
    
        cout << "\nDo you wnat to sort another data set?(y/n): ";
        cin >> repeat;
    } while (repeat == 'y' || repeat == 'Y');

    return 0;
}
