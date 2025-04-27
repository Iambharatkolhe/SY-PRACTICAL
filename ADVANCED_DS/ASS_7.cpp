#include<iostream>
using namespace std;

class Hashing_Quadrating {
public:
    Hashing_Quadrating *next;
    int Patent_Id;
    string name;
    int age;
    string Disease;
    string Treatment_Plan;

    Hashing_Quadrating(int P_I, string N, int A, string D, string T_P) {
        Patent_Id = P_I;
        next = NULL;
        name = N;
        age = A;
        Disease = D;
        Treatment_Plan = T_P;
    }
};

int flag = 0;
int size;
Hashing_Quadrating *obj[20];

Hashing_Quadrating* add_Edge(int P_I, string N, int A, string D, string T_P, int Size) {
    size = Size;
    if(flag == 0) {
        for(int i=0; i<Size; i++) {
            obj[i] = NULL;
        }
        flag = 1;
    }

    int index = P_I % Size;  
    Hashing_Quadrating *Newnode = new Hashing_Quadrating(P_I, N, A, D, T_P);  
    Hashing_Quadrating *temp;

    if(obj[index] == NULL) {
        obj[index] = Newnode;
        temp = Newnode;
    } else {
        temp = obj[index];
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = Newnode;
        temp = Newnode;
    }
    return temp;
}
void Dispaly() {
    cout << "Index     Position\n";
    for(int i = 0; i < size; i++) {
        cout << i;
        if(obj[i] != NULL) {
            Hashing_Quadrating *temp = obj[i];
            while(temp != NULL) {
                cout << " ------> [ Patent_Id: " << temp->Patent_Id 
                     << " , Name: " << temp->name 
                     << " , Age: " << temp->age 
                     << " , Disease: " << temp->Disease 
                     << " , Treatment: " << temp->Treatment_Plan << " ]";
                temp = temp->next;
            }
            cout << " ------> NULL\n";
        } else {
            cout << " ------> MT\n";
        }
    }
}


void search(int Patent_Id) {
    int index = Patent_Id % size;
    int flag = 0;
    Hashing_Quadrating *temp = obj[index];
    while(temp != NULL) {
        if(temp->Patent_Id == Patent_Id) {
            cout << "\nPatient is found:\n";
            cout << "Patent Id : " << temp->Patent_Id << endl;
            cout << "Name : " << temp->name << endl;
            cout << "Age : " << temp->age << endl;
            cout << "Disease : " << temp->Disease << endl;
            cout << "Treatment Plan : " << temp->Treatment_Plan << endl;
            flag = 1;
            return;
        } else {
            temp = temp->next;
        }
    }
    if(flag == 0) {
        cout << "\nNo user Found\n";
    }
}
void Update() {
    int choice, ID;
    cout << "Enter Patent ID you want to update: ";
    cin >> ID;

    int index = ID % size;
    Hashing_Quadrating *temp = obj[index];
    while (temp != NULL) {
        if (temp->Patent_Id == ID) {
            cout << "Enter what you want to update: \n";
            cout << "1. Name\n2. Age\n3. Disease\n4. Treatment Plan\n";
            cin >> choice;

            string UpName, UpDisease, UpTreatmentPlan;
            int UpAge;

            if (choice == 1) {
                cout << "Enter the updated Name: ";
                cin >> UpName;
                temp->name = UpName;
                cout << "Name has been updated to: " << temp->name << endl;
            } 
            else if (choice == 2) {
                cout << "Enter the updated Age: ";
                cin >> UpAge;
                temp->age = UpAge;
                cout << "Age has been updated to: " << temp->age << endl;
            } 
            else if (choice == 3) {
                cout << "Enter the updated Disease: ";
                cin >> UpDisease;
                temp->Disease = UpDisease;
                cout << "Disease has been updated to: " << temp->Disease << endl;
            } 
            else if (choice == 4) {
                cout << "Enter the updated Treatment Plan: ";
                cin >> UpTreatmentPlan;
                temp->Treatment_Plan = UpTreatmentPlan;
                cout << "Treatment Plan has been updated to: " << temp->Treatment_Plan << endl;
            } 
            else {
                cout << "Invalid choice.\n";
            }
            return; 
        }
        temp = temp->next;
    }

    cout << "Patent ID not found!\n";
}

int main() {
    cout << "Enter Total Size: ";
    cin >> size;
    int ch;
    do {
        cout << "\n Menu \n 1. Insert\n 2. Display\n 3. Search\n 4. Update\n 0. Exit\n";
        cin >> ch;
        switch (ch) {
            case 1: {
                int P_I, A;
                string N, D, T_P;
                cout << "Enter Patent Id: ";
                cin >> P_I;
                cout << "Enter Name: ";
                cin >> N;
                cout << "Enter Age: ";
                cin >> A;
                cout << "Enter Disease: ";
                cin >> D;
                cout << "Enter Treatment Plan: ";
                cin >> T_P;
                add_Edge(P_I, N, A, D, T_P, size);
                break;
            }
            case 2:
                Dispaly();
                break;
            case 3: {
                int Patent_id;
                cout << "Enter Patent id Number: ";
                cin >> Patent_id;
                search(Patent_id);
                break;
            }
            case 4:{
                Update();

                break;
            }
            case 0:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "You entered wrong choice" << endl;
        }
    } while (ch != 0);

    return 0;
}
