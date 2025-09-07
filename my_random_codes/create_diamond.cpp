#include <iostream>
#include <iomanip>
using namespace std;

void create_upward_triangle(int);
void create_downward_triangle(int);
void create_diamond(int);

int main() {
    create_diamond(5);
    return 0;
}

void create_upward_triangle(int l) {
    int b = l - 1;
    int k = 1;
    for (int i = 0; i < l; i++) {
        for (int i = 0; i <  b; i++) {
            cout << " ";
        }
    
        for (int i = 0; i < k; i++) {
            cout << "*";
        }
        b--;
        k++;
        k++;
        cout << endl;
    }
}

void create_downward_triangle(int l) {
    int b = 1;
    int s = (l * 2) - 1;
    for (int i = 0; i < l; i++) {
        for (int i = 0; i < b; i++) {
            cout << " ";
        }
    
        for (int i = 0; i < s; i++) {
            cout << "*";
        }
        b++;
        s--;
        s--;
        cout << endl;
    } 
}

void create_diamond(int l) {
    create_upward_triangle(l);
    create_downward_triangle(l-1);
}

    


