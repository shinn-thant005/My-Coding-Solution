#include <iostream>
using namespace std;

struct Distance {
    int feet;
    float inches;
};

void scale(Distance&, float);

int main() {
    Distance d;
    float s;
    cout << "Feet: ";
    cin >> d.feet;

    cout << "Inch: ";
    cin >> d.inches;

    cout << "Scale: ";
    cin >> s;

    cout << "Original Distance: " << d.feet << "' " << d.inches << "\"" << endl;
    scale(d, s);
    cout << "Scaled Distance: " << d.feet << "' " << d.inches << "\"";
    return 0;
}

void scale(Distance &d, float scale) {
    float inches = (d.feet * 12 + d.inches) * scale;
    d.feet = static_cast<int>(inches/12);
    d.inches = inches - (d.feet * 12) ;
}
