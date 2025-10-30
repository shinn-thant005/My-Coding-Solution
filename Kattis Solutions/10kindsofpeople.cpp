#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int r, c;
    cin >> r >> c;

    vector<string> grid(r);
    for (int i = 0; i < r; ++i)
        cin >> grid[i];

    vector<vector<int>> comp(r, vector<int>(c, -1));
    int comp_id = 0;

    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    // BFS labeling for connected components
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            if (comp[i][j] != -1) continue; // already visited

            queue<pair<int,int>> q;
            q.push({i, j});
            comp[i][j] = comp_id;
            char kind = grid[i][j];

            while (!q.empty()) {
                auto [x, y] = q.front();
                q.pop();

                for (int k = 0; k < 4; ++k) {
                    int nx = x + dx[k];
                    int ny = y + dy[k];
                    if (nx >= 0 && nx < r && ny >= 0 && ny < c
                        && comp[nx][ny] == -1 && grid[nx][ny] == kind) {
                        comp[nx][ny] = comp_id;
                        q.push({nx, ny});
                    }
                }
            }
            comp_id++;
        }
    }

    int n;
    cin >> n;
    while (n--) {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        r1--; c1--; r2--; c2--;

        if (comp[r1][c1] == comp[r2][c2]) {
            if (grid[r1][c1] == '0') cout << "binary\n";
            else cout << "decimal\n";
        } else {
            cout << "neither\n";
        }
    }
}
