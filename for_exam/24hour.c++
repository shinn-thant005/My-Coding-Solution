#include <iostream>
#include <iomanip>
using namespace std;

enum meridiem {am, pm};

struct Time {
    int hour;
    int minute;
    int second;
    meridiem duration;
};

int main() {
    Time t;
    string choice;

    cout << "Hour: ";
    cin >> t.hour;

    cout << "Minutes: ";
    cin >> t.minute;

    cout << "Second: ";
    cin >> t.second;

    cout << "Meridiem(am/pm): ";
    cin >> choice;

    t.duration = (choice == "am")? am: pm;

    int hour24 = t.hour % 12;
    if (t.duration == pm) {
        hour24 += 12;
    }

    cout << setw(2) << setfill('0') << hour24 << ":"
    << setw(2) << setfill('0') << t.minute << ":"
    << setw(2) << setfill('0') << t.second << endl;
    return 0;
}
