// Nicht
#include <bits/stdc++.h>
using namespace std;

vector<long long> buildFreq(int a1, int b1, int a2, int b2) {
    int minS = a1 + a2;
    int maxS = b1 + b2;

    vector<long long> freq(maxS + 1, 0);

    for (int s = minS; s <= maxS; s++) {
        int L = max(a1, s - b2);
        int R = min(b1, s - a2);
        if (L <= R) {
            freq[s] = R - L + 1;
        }
    }
    return freq;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a1, b1, a2, b2;
    int a3, b3, a4, b4;

    cin >> a1 >> b1 >> a2 >> b2;
    cin >> a3 >> b3 >> a4 >> b4;

    // Build frequency tables
    vector<long long> freqG = buildFreq(a1, b1, a2, b2);
    vector<long long> freqE = buildFreq(a3, b3, a4, b4);

    int Gmin = a1 + a2, Gmax = b1 + b2;
    int Emin = a3 + a4, Emax = b3 + b4;

    // Build cumulative sums for Emma
    vector<long long> cumE(Emax + 1, 0);
    long long running = 0;
    for (int s = 0; s <= Emax; s++) {
        running += freqE[s];
        cumE[s] = running;
    }

    // Count Gunnar wins
    long long gunnarWins = 0;
    for (int s = Gmin; s <= Gmax; s++) {
        long long fG = freqG[s];
        if (fG == 0) continue;

        int t = s - 1;
        long long numE = 0;
        if (t >= 0) numE = cumE[min(t, Emax)];

        gunnarWins += fG * numE;
    }

    // Build cumulative sums for Gunnar
    vector<long long> cumG(Gmax + 1, 0);
    running = 0;
    for (int s = 0; s <= Gmax; s++) {
        running += freqG[s];
        cumG[s] = running;
    }

    // Count Emma wins
    long long emmaWins = 0;
    for (int s = Emin; s <= Emax; s++) {
        long long fE = freqE[s];
        if (fE == 0) continue;

        int t = s - 1;
        long long numG = 0;
        if (t >= 0) numG = cumG[min(t, Gmax)];

        emmaWins += fE * numG;
    }

    // Determine result
    if (gunnarWins > emmaWins) {
        cout << "Gunnar\n";
    } else if (gunnarWins < emmaWins) {
        cout << "Emma\n";
    } else {
        cout << "Tie\n";
    }
}
