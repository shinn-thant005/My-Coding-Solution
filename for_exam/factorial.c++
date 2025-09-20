#include <iostream>
using namespace std;

long factorial(int n);

int main() {
    int n;
    cout << "Enter an integer: ";
    cin >> n;
    cout << "Factorial of " << n << " is " << factorial(n);
    return 0;

}

long factorial (int n) {
    if (n <= 1) {
        return n;
    }
    else {
        return n * factorial(n - 1);
    }
}
