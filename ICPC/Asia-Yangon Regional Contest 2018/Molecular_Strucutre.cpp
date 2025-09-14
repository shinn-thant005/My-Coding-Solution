#include <bits/stdc++.h>
using namespace std;

static const int MOD = 1'000'000'007;

inline int addmod(int a, int b){ a += b; if (a >= MOD) a -= MOD; return a; }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; 
    if (!(cin >> T)) return 0;
    while (T--) {
        int R, C; 
        cin >> R >> C;
        vector<string> G(R);
        for (int i = 0; i < R; ++i) cin >> G[i];

        // Build only local adjacency constraints:
        // forceUp[i][j]    => must choose UP at (i,j) (i>0 and G[i][j]==G[i-1][j] != '?')
        // forbidUp[i][j]   => cannot choose UP at (i,j) (i>0 and G[i][j]!=G[i-1][j], both concrete)
        // forceRight[i][j] => must choose RIGHT at (i,j) (j+1<C and G[i][j]==G[i][j+1] != '?')
        // forbidRight[i][j]=> cannot choose RIGHT at (i,j) (j+1<C and G[i][j]!=G[i][j+1], both concrete)
        vector<vector<uint8_t>> forceUp(R, vector<uint8_t>(C, 0));
        vector<vector<uint8_t>> forbidUp(R, vector<uint8_t>(C, 0));
        vector<vector<uint8_t>> forceRight(R, vector<uint8_t>(C, 0));
        vector<vector<uint8_t>> forbidRight(R, vector<uint8_t>(C, 0));

        auto concrete = [&](char ch){ return ch != '?'; };

        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                if (i > 0 && concrete(G[i][j]) && concrete(G[i-1][j])) {
                    if (G[i][j] == G[i-1][j]) forceUp[i][j] = 1;
                    else forbidUp[i][j] = 1;
                }
                if (j+1 < C && concrete(G[i][j]) && concrete(G[i][j+1])) {
                    if (G[i][j] == G[i][j+1]) forceRight[i][j] = 1;
                    else forbidRight[i][j] = 1;
                }
            }
        }

        // Profile DP over rows (bottom -> top), sweeping each row left->right.
        // State per row: map mask -> ways, where mask's bit j = an incoming-from-below into (i,j).
        unordered_map<uint64_t,int> cur, nextRow;
        cur.reserve(1<<12); cur.max_load_factor(0.7f);
        nextRow.reserve(1<<12); nextRow.max_load_factor(0.7f);
        cur[0] = 1;

        for (int i = R-1; i >= 0; --i) {
            nextRow.clear();

            for (auto &kv : cur) {
                uint64_t maskBelow = kv.first;
                int waysRow = kv.second;

                // Within the row, keep a tiny DP keyed by (partial nextMask, carry)
                struct Key { uint64_t nm; uint8_t carry; };
                struct KeyHash {
                    size_t operator()(Key const& k) const noexcept {
                        return std::hash<uint64_t>()((k.nm<<1) | k.carry);
                    }
                };
                struct KeyEq {
                    bool operator()(Key const& a, Key const& b) const noexcept {
                        return a.carry == b.carry && a.nm == b.nm;
                    }
                };
                unordered_map<Key,int,KeyHash,KeyEq> rowdp, rowdp2;
                rowdp.reserve(256); rowdp.max_load_factor(0.7f);
                rowdp2.reserve(256); rowdp2.max_load_factor(0.7f);

                rowdp[{0,0}] = waysRow;

                for (int j = 0; j < C; ++j) {
                    rowdp2.clear();

                    for (auto &kv2 : rowdp) {
                        uint64_t nm = kv2.first.nm;
                        int carry = kv2.first.carry;
                        int w = kv2.second;

                        int inBelow = ( (maskBelow >> j) & 1 );
                        int inLeft  = carry;

                        // At most one incoming into a cell (from left or from below)
                        if (inBelow + inLeft > 1) continue;

                        auto push = [&](int useUp, int useRight){
                            // Apply local adjacency constraints at (i,j)
                            if (useUp && forbidUp[i][j]) return;
                            if (!useUp && forceUp[i][j])  return;
                            if (useRight && forbidRight[i][j]) return;
                            if (!useRight && forceRight[i][j])  return;
                            if (useUp && useRight) return; // outdegree ≤ 1

                            // Build next partial state
                            uint64_t nm2 = nm;
                            int carry2 = 0;
                            if (useUp) nm2 |= (1ULL << j);
                            if (useRight) carry2 = 1;

                            // No other constraints: '?' cells are free, letters only restrict adjacency.
                            auto key = Key{nm2, (uint8_t)carry2};
                            int &ref = rowdp2[key];
                            ref = addmod(ref, w);
                        };

                        // Try NONE, UP, RIGHT
                        push(0,0);
                        push(1,0);
                        push(0,1);
                    }

                    rowdp.swap(rowdp2);
                }

                // End of row: carry must be zero (nothing flows into phantom (i, C))
                for (auto &kv2 : rowdp) {
                    if (kv2.first.carry) continue;
                    uint64_t nextMask = kv2.first.nm;
                    int w = kv2.second;
                    int &ref = nextRow[nextMask];
                    ref = addmod(ref, w);
                }
            }

            cur.swap(nextRow);
        }

        // After top row, no edges may go upward out of the grid
        int ans = cur.count(0) ? cur[0] : 0;
        cout << ans << "\n";
    }
    return 0;
}
