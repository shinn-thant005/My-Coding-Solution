#include <iostream> 
using namespace std;

int lcm(int, int, int);

int main() {
    int n1, n2, n3;
    cin >> n1 >> n2 >> n3;
    cout << lcm(n1, n2, n3);
    return 0;
}

int lcm(int n1, int n2, int n3) {
    int i = 1;
    int m;
    int k = max(n1, max(n2, n3));
    
    while (true) {
        m = k * i;
        if (m % n1 == 0 && m % n2 == 0 && m % n3 == 0) {
            return m;
        }
        i++;
    }
}

