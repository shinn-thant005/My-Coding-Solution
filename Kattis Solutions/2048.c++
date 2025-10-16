#include <bits/stdc++.h>
using namespace std;

vector<int> processRow(vector<int> row) {
    // Step 1: Remove zeros
    vector<int> temp;
    for (int x : row) if (x != 0) temp.push_back(x);

    // Step 2: Merge adjacent equal tiles
    for (int i = 0; i + 1 < (int)temp.size(); i++) {
        if (temp[i] == temp[i+1]) {
            temp[i] *= 2;
            temp[i+1] = 0;
            i++; // skip next
        }
    }

    // Step 3: Remove zeros again
    vector<int> result;
    for (int x : temp) if (x != 0) result.push_back(x);

    // Step 4: Pad with zeros to length 4
    while (result.size() < 4) result.push_back(0);

    return result;
}

int main() {
    vector<vector<int>> board(4, vector<int>(4));
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            cin >> board[i][j];

    int move;
    cin >> move;

    if (move == 0) { // left
        for (int i = 0; i < 4; i++)
            board[i] = processRow(board[i]);
    } 
    else if (move == 2) { // right
        for (int i = 0; i < 4; i++) {
            reverse(board[i].begin(), board[i].end());
            board[i] = processRow(board[i]);
            reverse(board[i].begin(), board[i].end());
        }
    } 
    else if (move == 1) { // up
        for (int j = 0; j < 4; j++) {
            vector<int> col;
            for (int i = 0; i < 4; i++) col.push_back(board[i][j]);
            col = processRow(col);
            for (int i = 0; i < 4; i++) board[i][j] = col[i];
        }
    } 
    else if (move == 3) { // down
        for (int j = 0; j < 4; j++) {
            vector<int> col;
            for (int i = 0; i < 4; i++) col.push_back(board[i][j]);
            reverse(col.begin(), col.end());
            col = processRow(col);
            reverse(col.begin(), col.end());
            for (int i = 0; i < 4; i++) board[i][j] = col[i];
        }
    }

    // Output final board
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
}
