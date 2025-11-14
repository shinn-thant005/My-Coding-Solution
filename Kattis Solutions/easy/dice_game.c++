// Own
#include <bits/stdc++.h>
using namespace std;

int main() {
    int a1, b1, a2, b2;
    int c1, d1, c2, d2;
    cin >> a1 >> b1 >> a2 >> b2;
    cin >> c1 >> d1 >> c2 >> d2;

    vector<int> G, E;

    // Generate all possible sums for Gunnar
    for (int i = a1; i <= b1; i++)
        for (int j = a2; j <= b2; j++)
            G.push_back(i + j);

    // Generate all possible sums for Emma
    for (int i = c1; i <= d1; i++)
        for (int j = c2; j <= d2; j++)
            E.push_back(i + j);

    long long gWins = 0, eWins = 0;

    // Count pair outcomes
    for (int g : G)
        for (int e : E)
            if (g > e) gWins++;
            else if (e > g) eWins++;

    if (gWins > eWins)
        cout << "Gunnar\n";
    else if (eWins > gWins)
        cout << "Emma\n";
    else
        cout << "Tie\n";

    return 0;
}
