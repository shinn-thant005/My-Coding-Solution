#include <iostream>
using namespace std;

struct student {
    char name[50];
    long roll_no;
};

int main() {
    student students[100];
    int n;

    cout << "Enter number of students (up to 100): ";
    cin >> n;

    cin.ignore();

    for (int i = 0; i < n; i++) {
        cout << "Enter name of student " << i + 1 << ": ";
        cin.getline(students[i].name, 50);

        cout << "Enter roll number of student " << i + 1 << ": ";
        cin >> students[i].roll_no;

        cin.ignore();
    }

    cout << "\n--- Student Records ---\n";
    for (int i = 0; i < n; i++) {
        cout << "Name: " << students[i].name << endl;
        cout << "Roll No.: " << students[i].roll_no << endl;
    }

    return 0;
}
