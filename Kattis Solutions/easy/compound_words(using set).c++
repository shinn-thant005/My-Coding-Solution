// Nicht
#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    string word;
    vector<string> words;

    while(cin >> word) {
        words.push_back(word);
    }

    set<string> compound;
    int size = words.size();

    for (int i = 0; i < size; i++) {
       for (int j = 0; j < size; j++) {
        if (words[i] == words[j]) continue;
        compound.insert(words[i] + words[j]);
       }
    }

    for (const string& s : compound) {
        cout << s << endl;
    }

}


