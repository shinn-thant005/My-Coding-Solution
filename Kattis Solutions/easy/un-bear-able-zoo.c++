// OWN
#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    int Tcount = 1;

    while(true) {
        vector<string> animals;
        
        cin >> T;
        if (T == 0) break;
        cin.ignore();
    
        while(T--) {
            string line;
            string lastWord;

            getline(cin, line);

            size_t lastPos = line.find_last_of(' ');

            if (lastPos == string::npos) {
                lastWord = line;
            }
            else {
                lastWord = line.substr(lastPos + 1);
            }
            for (auto& s: lastWord) {
                s = tolower(s);
            }
            animals.push_back(lastWord);
        }

        vector<string> result(animals);

        sort(result.begin(), result.end());
        auto new_end = unique(result.begin(), result.end());
        result.erase(new_end, result.end());

        cout << "List " << Tcount << ":" << endl;
        for (string s: result) {
            int animalC = count(animals.begin(), animals.end(), s);
            cout << s << " | " << animalC << endl;
        }
        Tcount++;
    }
    
    
    return 0;
}
