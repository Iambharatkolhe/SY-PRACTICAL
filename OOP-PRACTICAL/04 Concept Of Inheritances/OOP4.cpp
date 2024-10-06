#include <iostream>
#include <iomanip>
using namespace std;

class Person {
public:
    string name;
    int age;
    string gender;
    double contactNumber;
    string address;
    double id;

    void accept() {
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Age: ";
        cin >> age;
        cout << "Enter Gender: ";
        cin >> gender;
        cout << "Enter Contact Number: ";
        cin >> contactNumber;
        cout << "Enter Address: ";
        cin >> address;
        cout << "Enter ID Number: ";
        cin >> id;
    }

    void display() {
        cout << left << setw(10) << name
             << setw(5) << age
             << setw(10) << gender
             << setw(15) << contactNumber
             << setw(15) << id;
    }
};

class Doctor : public Person {
public:
    string specialization;
    int salary;

    void accept() {
        Person::accept();
        cout << "Enter Specialization: ";
        cin >> specialization;
        cout << "Enter Salary: ";
        cin >> salary;
    }

    void display() {
        Person::display();
        cout << setw(15) << specialization
             << setw(10) << salary << endl;
    }
};

class Nurse : public Person {
public:
    string shift;
    int salary;

    void accept() {
        Person::accept();
        cout << "Enter Shift (Day/Night): ";
        cin >> shift;
        cout << "Enter Salary: ";
        cin >> salary;
    }

    void display() {
        Person::display();
        cout << setw(10) << shift
             << setw(10) << salary << endl;
    }
};

class AdministrativeStaff : public Person {
public:
    string department;
    int salary;

    void accept() {
        Person::accept();
        cout << "Enter Department: ";
        cin >> department;
        cout << "Enter Salary: ";
        cin >> salary;
    }

    void display() {
        Person::display();
        cout << setw(15) << department
             << setw(10) << salary << endl;
    }
};

int main() {
    int i, ch, size;
    Doctor doctors[20];
    Nurse nurses[20];
    AdministrativeStaff adminStaff[20];

    int docCount = 0, nurseCount = 0, adminCount = 0;

    do {
        cout << "\n1. Add Doctor\n2. Add Nurse\n3. Add Administrative Staff\n4. Display Doctors\n5. Display Nurses\n6. Display Administrative Staff\n7. Exit\n";
        cout << "Enter your choice: ";
        cin >> ch;

        switch(ch) {
            case 1:
                cout << "Enter the number of doctors to add: ";
                cin >> size;
                for(i = 0; i < size; i++) {
                    doctors[docCount].accept();
                    docCount++;
                }
                break;

            case 2:
                cout << "Enter the number of nurses to add: ";
                cin >> size;
                for(i = 0; i < size; i++) {
                    nurses[nurseCount].accept();
                    nurseCount++;
                }
                break;

            case 3:
                cout << "Enter the number of administrative staff to add: ";
                cin >> size;
                for(i = 0; i < size; i++) {
                    adminStaff[adminCount].accept();
                    adminCount++;
                }
                break;

            case 4:
                cout << left << setw(10) << "Name" 
                     << setw(5) << "Age" 
                     << setw(10) << "Gender"
                     << setw(15) << "Contact No"
                     << setw(15) << "ID"
                     << setw(15) << "Specialization"
                     << setw(10) << "Salary" << endl;
                cout << ".............................................................................." << endl;
                for(i = 0; i < docCount; i++) {
                    doctors[i].display();
                }
                break;

            case 5:
                cout << left << setw(10) << "Name" 
                     << setw(5) << "Age" 
                     << setw(10) << "Gender"
                     << setw(15) << "Contact No"
                     << setw(15) << "ID"
                     << setw(10) << "Shift"
                     << setw(10) << "Salary" << endl;
                cout << ".............................................................................." << endl;
                for(i = 0; i < nurseCount; i++) {
                    nurses[i].display();
                }
                break;

            case 6:
                cout << left << setw(10) << "Name" 
                     << setw(5) << "Age" 
                     << setw(10) << "Gender"
                     << setw(15) << "Contact No"
                     << setw(15) << "ID"
                     << setw(15) << "Department"
                     << setw(10) << "Salary" << endl;
                cout << ".............................................................................." << endl;
                for(i = 0; i < adminCount; i++) {
                    adminStaff[i].display();
                }
                break;

            case 7:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while(ch != 7);

    return 0;
}
