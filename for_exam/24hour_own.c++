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

    if (t.duration == pm && t.hour != 12) {
        t.hour += 12;
    }

    if (t.duration == am && t.hour == 12) {
        t.hour = 0;
    }

    cout << setw(2) << setfill('0') << t.hour << ":"
    << setw(2) << setfill('0') << t.minute << ":"
    << setw(2) << setfill('0') << t.second << endl;
    return 0;
}
