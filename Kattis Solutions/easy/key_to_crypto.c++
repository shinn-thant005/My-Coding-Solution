// OWN
#include <bits/stdc++.h>
using namespace std;

int main() {
    map<char, int> alpha;
    map<int, char> revAlpha;

    for (int i = 0; i < 26; i++) {
        alpha['A' + i] = i;
        revAlpha[i] = 'A' + i;
    }

    string cipher, secret;
    cin >> cipher >> secret;

    int secLen = secret.length();
    string message (cipher.length(), '?');
    string temp = secret;
    int i = 0;
    while(i < cipher.length()) {
        for (int j = 0; j < secLen && i < cipher.length(); j++) {
            int newAlpha = alpha[cipher[i]] - alpha[temp[j]];
            newAlpha = (newAlpha % 26 + 26) % 26;

            message[i] = revAlpha[newAlpha];
            temp[j] = message[i];
            i++;
        }
    }
    cout << message;
    return 0;
}
