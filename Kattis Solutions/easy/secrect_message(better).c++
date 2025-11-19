#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    cin.ignore();

    while (N--) {
        string s;
        getline(cin, s);

        int L = s.length();
        int K = ceil(sqrt((double)L));
        int M = K * K;

        // pad message
        s.append(M - L, '*');

        // create original table
        vector<vector<char>> table(K, vector<char>(K));
        int idx = 0;
        for (int i = 0; i < K; i++)
            for (int j = 0; j < K; j++)
                table[i][j] = s[idx++];

        // rotated table (90 degrees clockwise)
        vector<vector<char>> rot(K, vector<char>(K));
        for (int i = 0; i < K; i++)
            for (int j = 0; j < K; j++)
                rot[j][K - 1 - i] = table[i][j];

        // read rotated table row-major, skipping '*'
        string result;
        for (int i = 0; i < K; i++)
            for (int j = 0; j < K; j++)
                if (rot[i][j] != '*')
                    result += rot[i][j];

        cout << result << "\n";
    }

    return 0;
}
