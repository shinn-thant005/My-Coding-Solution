#include <bits/stdc++.h>
using namespace std;

int main() {
    for (int t = 0; t < 100; t++) {
        int n,m;
        int error = 0;
        int bPrice;
        cin >> n >> m;
        if (n == 0 && m == 0) break;
        int a[n];   
        int b[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i] >> b[i];
        }

        bPrice = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] > m) {
                error++;
                if (i == bPrice) {
                    bPrice++;
                }
                continue;
            }
            float ppt = static_cast<float>(b[i]) / static_cast<float>(a[i]);
            float bestPPT = static_cast<float>(b[bPrice]) / static_cast<float>(a[bPrice]);
            if (ppt < bestPPT) {
                bPrice = i;
            }
            else if (ppt == bestPPT) {
                if (a[i] > a[bPrice]) {
                    bPrice = i;
                }
            }
        }
        if (error == n) {
            cout << "No suitable tickets offered" << endl;
        }
        else {
            cout << "Buy " << a[bPrice] << " tickets for $" << b[bPrice] << endl;
        }
    }
    return 0;
}
