#include <iostream>
#include <iomanip> 
#include <cstring>
using namespace std;


struct Address {
    char houseno[20];
    char street[50];
    char quarter[50];
    char city[50];
    char state[50];
};


struct Employee {
    int id;
    char name[50];
    Address address;
};

int main() {
    Employee e1 = {1, "Kyipyar", {"1", "Main", "7", "Naypyitaw", "Myanmar"}};
    Employee e2;

    cout << "Enter Employee ID: ";
    cin >> e2.id;
    cin.ignore();

    cout << "Enter Employee Name: ";
    cin.getline(e2.name, 50);

    cout << "Enter House No: ";
    cin.getline(e2.address.houseno, 20);

    cout << "Enter Street: ";
    cin.getline(e2.address.street, 50);

    cout << "Enter Quarter: ";
    cin.getline(e2.address.quarter, 50);

    cout << "Enter City: ";
    cin.getline(e2.address.city, 50);

    cout << "Enter State: ";
    cin.getline(e2.address.state, 50);

    cout << endl;
    cout << left << setw(18) << "Employee ID"
         << setw(20) << "Employee Name"
         << "Employee Address" << endl;


    cout << left << setw(18) << e1.id
         << setw(20) << e1.name
         << "No. " << e1.address.houseno << ", "
         << e1.address.street << " Road, "
         << "Quater (" << e1.address.quarter << "), "
         << e1.address.city << ", "
         << e1.address.state << endl;

    cout << left << setw(18) << e2.id
         << setw(20) << e2.name
         << "No. " << e2.address.houseno << ", "
         << e2.address.street << " Road, "
         << "Quater (" << e2.address.quarter << "), "
         << e2.address.city << ", "
         << e2.address.state << endl;

    return 0;
}
