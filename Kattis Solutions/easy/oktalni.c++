#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
    string binary;
    cin >> binary;
    int remainder = binary.size() % 3;
    if (remainder == 1) binary = "00" + binary;
    else if (remainder == 2) binary = "0" + binary;
    string result = "";
    for (int i = 0; i < binary.size(); i += 3) {
        string group = binary.substr(i, 3);
        int octal = (group[0] - '0') * 4 + (group[1] - '0') * 2 + (group[2] - '0') * 1;
        result += to_string(octal);
    }
    cout << result;
    return 0;
}


