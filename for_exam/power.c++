#include <iostream>
using namespace std;

double power(double n, int p = 2) {
    double result = 1;
    for (int i = 0; i < p; i++) {
        result *= n;
    }
    return result;
}

char power(char n, int p = 2) {
    int result = 1;
    int m = static_cast<int>(n);
    for (int i = 0; i < p; i++) {
        result *= m;
    }
    return result;
}

float power(float n, int p = 2) {
    float result = 1;
    for (int i = 0; i < p; i++) {
        result *= n;
    }
    return result;
}

int main() {
    double n1 = 3.5;
    char n2 = 'A';
    float n3 = 5.5;

    cout << power(n1) << endl;
    cout << power(n1, 3) << endl;

    cout << (int)power(n2) << endl;
    cout << (int)power(n2, 3) << endl;

    cout << power(n3) << endl;
    cout << power(n3, 3) << endl;
}
