#include <iostream>
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
    string ap;
    cout << "Hour: ";
    cin >> t.hour;

    cout << "Minutes: ";
    cin >> t.minute;

    cout << "Second: ";
    cin >> t.second;

    cout << "Meridiem(am/pm): ";
    cin >> ap;

    if (ap == "am") {
        t.duration = am;
    }
    else if (ap == "pm") {
        t.duration = pm;
    }

    string minute = to_string(t.minute);
    string second = to_string(t.second);

    if (t.duration == pm && t.hour != 12) {
        t.hour += 12;
    }

    if (t.duration == am && t.hour == 12) {
        t.hour = 0;
    }

    string hour = to_string(t.hour);

    if (t.hour < 10) {
        hour = string("0") + hour;
    }
    if (t.minute < 10) {
        minute = string("0") + minute;
    }
    if (t.second < 10) {
        second = string("0") + second;
    }

    cout << hour << ":" << minute << ":" << second;

    return 0;
}
