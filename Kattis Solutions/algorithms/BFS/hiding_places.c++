#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    // Knight movement vectors
    int dx[8] = { 2, 2, -2, -2, 1, 1, -1, -1 };
    int dy[8] = { 1, -1, 1, -1, 2, -2, 2, -2 };

    while (T--) {
        string s;
        cin >> s;

        // Convert chess notation (e.g., "d5") to coordinates
        int sx = s[0] - 'a';   // file a-h -> 0-7
        int sy = s[1] - '1';   // rank 1-8 -> 0-7

        // BFS distance grid
        vector<vector<int>> dist(8, vector<int>(8, -1));
        queue<pair<int,int>> q;

        dist[sx][sy] = 0;
        q.push({sx, sy});

        // BFS
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            for (int k = 0; k < 8; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];

                if (nx >= 0 && nx < 8 && ny >= 0 && ny < 8 && dist[nx][ny] == -1) {
                    dist[nx][ny] = dist[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }

        // Find maximum distance
        int maxd = 0;
        for (int i = 0; i < 8; i++)
            for (int j = 0; j < 8; j++)
                maxd = max(maxd, dist[i][j]);

        // Collect all squares with distance = maxd
        vector<pair<int,int>> ans;
        for (int i = 0; i < 8; i++)
            for (int j = 0; j < 8; j++)
                if (dist[i][j] == maxd)
                    ans.push_back({i, j});

        // Sort: rank descending, file ascending
        sort(ans.begin(), ans.end(), [](auto &A, auto &B) {
            if (A.second != B.second)
                return A.second > B.second;   // higher rank first
            return A.first < B.first;         // leftmost file first
        });

        // Output
        cout << maxd << " ";
        for (auto &p : ans) {
            char file = 'a' + p.first;
            char rank = '1' + p.second;
            cout << file << rank << " ";
        }
        cout << "\n";
    }

    return 0;
}
