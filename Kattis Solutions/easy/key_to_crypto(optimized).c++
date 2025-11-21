#include <bits/stdc++.h>
using namespace std;

int main() {
    string cipher, secret;
    cin >> cipher >> secret;

    int n = cipher.length();

    // The evolving key: starts as the secret, then grows by adding decoded letters.
    string key = secret;
    string message(n, '?');   // placeholder string of size n

    for (int i = 0; i < n; i++) {
        // Convert chars to numbers 0–25
        int c = cipher[i] - 'A';
        int k = key[i] - 'A';

        // Decode the letter
        int m = (c - k + 26) % 26;
        char decoded = char(m + 'A');

        message[i] = decoded;

        // Append this decoded character to the key
        key.push_back(decoded);
    }

    cout << message << endl;
    return 0;
}
