#include <iostream>
using namespace std;

int main() {
    char option;
    do {
        int arr[10];
        cout << "Enter integers: ";
        for (int i = 0; i < 10; i++) {
            cin >> arr[i];
        }

        for (int i = 0; i < 10 ; i++) {
            int min = i;
            for (int j = i + 1; j < 10; j++) {
                if (arr[min] > arr[j]) {
                    min = j;
                }
            }
            swap(arr[i], arr[min]);
        }

        cout << "Sorted Array: ";
        for (int i = 0; i < 10; i++) {
            cout << arr[i] << " ";
        }
        cout << "\nDo you want to sort another data set(Y/N): ";
        cin >> option;
    } while (option != 'N');
  return 0;
}
