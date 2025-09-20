#include <iostream>
using namespace std;


int main() {
    int rows = 5;
    int blank = rows - 1;
    int stars = 1;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < blank; j++) {
            cout << " ";
        }

        for (int k = 0; k < stars; k++) {
            cout << "*";
        }
        cout << endl;

        stars += 2;
        blank--;
    }

    for (int i = 0; i < 3; i++) {
        cout << "   ***" << endl;
    }
}
