#include <iostream>
using namespace std;

void bsort(int* ptr);
void Swap(int*, int*);

int main() {
    int arr[10];
    int *ptr = arr;
    for (int i = 0; i < 10; i++) {
        cin >> arr[i];
    }

    cout << "Data Before Sorting: ";
    for (int i = 0; i < 10; i++) {
        cout << *(ptr + i) << " ";
    }
    cout << endl;

    bsort(ptr);

    cout << "Data After Sorting: ";
    for (int i = 0; i < 10; i++) {
        cout << *(ptr + i) << " ";
    }
    
}

void bsort(int *ptr) {
    for (int i = 0; i < 10; i++) {
        for (int j = i + 1; j < 10; j++) {
            if(*(ptr + i)< *(ptr + j)) {
                Swap((ptr + i), (ptr + j));
            }
        }
    }
}

void Swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
