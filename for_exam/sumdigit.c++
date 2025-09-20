#include <iostream>
using namespace std;

int sumdigit(int);

int main() {
    int n;
    cin >> n;
    cout << sumdigit(n);
    return 0;
}

int sumdigit(int n) {
    int result = 0;
    n = abs(n);
    while (n > 0) {
        result += n % 10;
        n /= 10;
    }
    
    return result;
}
