#include <iostream>
#include <iomanip> 
#include <string> 

using namespace std;

class TRAINING {
public:
    int rollno, rate, Experience, teachearfeedback;
    string name;
    string Year;
    float average;

    void accept(int studentNumber) {
        cout << "Enter details for student " << studentNumber << ":\n";
        cout << "Enter Roll No: ";
        cin >> rollno;
        cout << "Enter Class (Year): ";
        cin >> Year;
        cout << "Enter Name: ";
        cin >> name;
    }

    void display() {
        cout << "| " << setw(8) << rollno << " | " << setw(12) << name << " | " << setw(10) << Year << " |" << endl;
    }

    void feedback(int studentNumber) {
        cout << "Enter feedback for student " << studentNumber << ":\n\n";
        cout << "Rate the program (1-very poor, 5-excellent):" ;
        cin >> rate;
         cout<<"\n";
        cout << "Rate your experience (1-very poor, 5-excellent): ";
        cin >> Experience;
          cout<<"\n";
        cout << "Rate the teacher's feedback (1-very poor, 5-excellent): ";
        cin >> teachearfeedback;
        cout<<"\n\n";
    }

    int Average() {
        average = (rate + Experience + teachearfeedback) / 3.0;
        return average;
    }
};

int main() {
    int N, ch, presentroll, flag = 0, totalstudent = 0, i,n;
     int student=1;
    string presentname;

    TRAINING obj[20];

    cout << "Enter the How Many Student: ";
    cin >> N;

    do {
        cout << "\nMenu\n1. Accept\n2. Display\n3. Use Linear Search\n4. Use Binary Search\n5. Provide Feedback\n6. Display Feedback\n7. Exit\n";
        cin >> ch;

        switch (ch) {
            case 1:
            
                for (int i = totalstudent; i < N; i++) {
                    obj[totalstudent].accept(totalstudent+1);
                    totalstudent++;
                }
                break;

            case 2:
                if (totalstudent == 0) {
                    cout << "Please enter data first." << endl;
                } else {
                    cout << "| " << setw(8) << "Roll No" << " | " << setw(12) << "Name" << " | " << setw(10) << "Year" << " |" << endl;
                    cout << "--------------------------------------------" << endl;
                    for (int i = 0; i < totalstudent; i++) {
                        obj[i].display();
                    }
                }
                break;

            case 3:
                // Linear search for student by roll number and name
                flag = 0;
                cout << "Enter Roll No you want to search: ";
                cin >> presentroll;
                cout << "Enter Name you want to search: ";
                cin >> presentname;
                for (int i = 0; i < totalstudent; i++) {
                    if (obj[i].rollno == presentroll && obj[i].name == presentname) {
                        cout << "Student Attend" << endl;
                        flag = 1;
                        break;
                    }
                }
                if (flag == 0) {
                    cout << "Student not found" << endl;
                }
                break;

            case 4: {
                // Bubble sort based on roll number
                for (int i = 0; i < totalstudent - 1; i++) {
                    for (int j = 0; j < totalstudent - 1 - i; j++) {
                        if (obj[j].rollno > obj[j + 1].rollno) {
                            // Swap the objects
                            TRAINING temp = obj[j];
                            obj[j] = obj[j + 1];
                            obj[j + 1] = temp;
                        }
                    }
                }

                // Display sorted list
                cout << "Sorted list:\n";
                cout << "| " << setw(8) << "Roll No" << " | " << setw(12) << "Name" << " | " << setw(10) << "Year" << " |" << endl;
                cout << "--------------------------------------------" << endl;
                for (int i = 0; i < totalstudent; i++) {
                    obj[i].display();
                }

                // Binary search implementation
                int high = totalstudent - 1, low = 0, mid;
                cout << "Enter the roll number you want to search: ";
                cin >> presentroll;
                 cout << "Enter the Name you want to search: ";
                cin >> presentname;
                

                flag = 0;
                while (low <= high) {
                    mid = (low + high) / 2;
                    if (obj[mid].rollno == presentroll && obj[mid].name == presentname) {
                        cout << "Student Attend " << mid + 1 << endl;
                        flag = 1;
                        break;
                    } else if (obj[mid].rollno < presentroll) {
                        low = mid + 1;
                    } else {
                        high = mid - 1;
                    }
                }
                if (flag == 0) {
                    cout << "Student not found" << endl;
                }
                break;
            }

            case 5:
                for (i = 0; i < totalstudent; i++) {
                    obj[i].feedback(i + 1);
                }
                break;

            case 6:
           
                for (i = 0; i < totalstudent; i++) {
                    float Total = obj[i].Average();

                    cout<<"_____________["<<student<<"]  Students Feedback Is______________\n";
                    student++;
                     cout<<"\n";

                    if (Total <= 2) {
                        cout << "__________This student's feedback is poor.__________" << endl;
                    } else if (Total <= 4) {
                        cout << "__________This student's feedback is satisfactory.__________" << endl;
                    } else {
                        cout << "__________This student's feedback is excellent.__________" << endl;
                    }
                    cout<<"\n";
                }
                break;

            case 7:
                // Exit the program
                cout << "Exiting... THANK YOU" << endl;
                break;

            default:
                cout << "Invalid choice, please try again." << endl;
        }

    } while (ch != 7);

    return 0;
}
