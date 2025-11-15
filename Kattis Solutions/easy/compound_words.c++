// OWN
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios:: sync_with_stdio(false);
    cin.tie(nullptr);

    string str;
    vector<string> words;
    while(cin >> str) {
        words.push_back(str);
    }

    vector<string> newWords;
    int size = words.size();
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (words[i] == words[j]) continue;
            newWords.push_back(words[i] + words[j]);
        }
    }

    sort(newWords.begin(), newWords.end());
    auto it = unique(newWords.begin(), newWords.end());
    newWords.erase(it, newWords.end());

    for (string x : newWords) {
        cout << x << endl;
    }
    return 0;
}
