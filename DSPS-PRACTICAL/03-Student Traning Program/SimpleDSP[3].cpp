#include <iostream>
#include <string>  
using namespace std;

class TRAINING {
public:
    int rollno, Year;
    string name;

    // Function to accept student details
    void accept() {
        cout << "Enter The Roll No: ";
        cin >> rollno;
        cout << "Enter the Class (Year): ";
        cin >> Year;
        cout << "Enter The Name of Student: ";
        cin >> name;
    }

    // Function to display student details
    void display() {
        cout << "Roll No: " << rollno << endl;
        cout << "Name: " << name << endl;
        cout << "Class (Year): " << Year << endl;
    }
};

int main() {
    int N, ch, presentroll, flag = 0;
    string presentname;

    // Create an array of TRAINING objects
    TRAINING obj[10];

    cout << "Enter How Many Students: ";
    cin >> N;

    do {
        cout << "\nMenu\n1. Accept\n2. Display\n3. Use Linear Search\n4. Use Binary Search\n5. Exit\n";
        cin >> ch;

        switch (ch) {
            case 1:
                // Accept details for N students
                for (int i = 0; i < N; i++) {
                    obj[i].accept();
                }
                break;

            case 2:
                // Display details for N students
                for (int i = 0; i < N; i++) {
                    obj[i].display();
                }
                break;

            case 3:
                // Linear search for student by roll number and name
                flag = 0;
                cout << "Enter Roll No you want to search: ";
                cin >> presentroll;
                cout << "Enter Name you want to search: ";
                cin >> presentname;
                for (int i = 0; i < N; i++) {
                    if (obj[i].rollno == presentroll && obj[i].name == presentname) {
                        cout << "Student is present" << endl;
                        flag = 1;
                        break;
                    }
                }
                if (flag == 0) {
                    cout << "Student is NOT present" << endl;
                }
                break;

            case 4: {
                // Bubble sort based on roll number
                for (int i = 0; i < N - 1; i++) {
                    for (int j = 0; j < N - 1 - i; j++) {
                        if (obj[j].rollno > obj[j + 1].rollno) {
                            // Swap the objects
                            TRAINING temp = obj[j];
                            obj[j] = obj[j + 1];
                            obj[j + 1] = temp;
                        }
                    }
                }

                // Display sorted list
                cout << "Your sorted array is:\n";
                for (int i = 0; i < N; i++) {
                    obj[i].display();
                }

                // Binary search implementation
                int high = N - 1, low = 0, mid;
                cout << "Enter the roll number you want to search: ";
                cin >> presentroll;

                flag = 0;
                while (low <= high) {
                    mid = (low + high) / 2;
                    if (obj[mid].rollno == presentroll) {
                        cout << "Key is found at position " << mid + 1 << endl;
                        flag = 1;
                        break;
                    } else if (obj[mid].rollno < presentroll) {
                        low = mid + 1;
                    } else {
                        high = mid - 1;
                    }
                }
                if (flag == 0) {
                    cout << "Element not found" << endl;
                }
                break;
            }

            case 5:
                // Exit the program
                cout << "Exiting... THANK YOU" << endl;
                break;

            default:
                cout << "Invalid choice, please try again." << endl;
        }

    } while (ch != 5);

    return 0;
}
