#include <iostream>
using namespace std;

int main() {
    int n = 6;
    int d = 2;
    while (n != 1) {
        if (n % d == 0) {
            n /= d;
            continue;
        }
        else {
            d++;
            continue;
        }
    }
}
