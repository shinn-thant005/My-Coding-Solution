#include <iostream>
using namespace std;

void determine_tri(int, int, int);

int main() {
    int s1, s2, s3;
    char more;

    while(true) {
        cout << "Enter three sides: ";
        cin >> s1 >> s2 >> s3;

        if (s1 + s2 > s3 && s1 + s3 > s2 && s2 + s3 > s1) {
            cout << "Triangle is valid. ";
            determine_tri(s1, s2, s3);
        }
        else {
            cout << "Triangle is not valid.";
        }

        cout << "\nDo you wish to continue (y/n)? ";
        cin >> more;
        if (more == 'N' || more == 'n') {
            break;
        }
    }
    return 0;
}


void determine_tri(int s1, int s2, int s3) {
    if (s1 == s2 && s2 == s3) {
        cout << "Equilateral Triangle.";
    }
    else if (s1 == s2 || s1 == s3 || s2 == s3) {
        cout << "Isosceles Triangle.";
    }
    else if (s1 != s2 && s1 != s3 && s2 != s3) {
        cout << "Scalene Triangle.";
    }
    if ((s1 * s1 + s2 * s2) == (s3 * s3) || (s1 * s1 + s3 * s3) == (s2 * s2) || (s2 * s2 + s3 * s3) == (s1 * s1)) {
        cout << " Right Triangle.";
    }
}
