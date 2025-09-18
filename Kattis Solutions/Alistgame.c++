#include <iostream>
using namespace std;

int prime_factors(int n) {
    int count = 0;
    for(int i = 2; i * i <= n; i++) {
        while(n % i == 0) {
            n /= i;
            count++;
        }
    }

    if (n > 1) {
        count++;
    }
    return count;
}

int main() {
    int n;
    int point;
    cin >> n;
    point = prime_factors(n);
    cout << point << endl;
    return 0;
}
