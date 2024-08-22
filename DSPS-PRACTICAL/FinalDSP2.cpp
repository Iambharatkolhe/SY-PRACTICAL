#include <iostream>
using namespace std;

class NBook {
public:
    int Cost;
    string Title;

    void Accept() {
        cout << "Enter book title: ";
        cin >> Title;
        cout << "Enter Book Cost: ";
        cin >> Cost;
        cout << "\n";
    }

    void display() {
        cout << "Title: " << Title << "\n";
        cout << "Cost: " << Cost << "\n\n";
    }
};

int main() {
    int N, ch, i, j, temp;
    string tem;
    NBook obj[10], obj1[10],obj2[10];

    cout << "Enter How Many Books: ";
    cin >> N;

    do {
        cout << "\nMenu\n1. Accept\n2. Display\n3. Sort\n4. Display less than 500\n5. Display greater than 500\n6. Duplicate\n7. Exit\n";
        cin >> ch;

        switch (ch) {
        case 1:
            for (i = 0; i < N; i++) {
                obj[i].Accept();
            }
            break;

        case 2:
            for (i = 0; i < N; i++) {
                obj[i].display();
            }
            break;

        case 3:
            for (i = 0; i < N; i++) {
                for (j = i + 1; j < N; j++) {
                    if (obj[i].Cost < obj[j].Cost) {
                        // Swap the Cost
                        temp = obj[i].Cost;
                        obj[i].Cost = obj[j].Cost;
                        obj[j].Cost = temp;

                        // Swap the Title
                        tem = obj[i].Title;
                        obj[i].Title = obj[j].Title;
                        obj[j].Title = tem;
                    }
                }
            }
            cout << "Sorting is done.\n";
            break;

        case 4:
            int enter;
            enter = 0; 
            int count;
            count=0;
          // Reset the counter
            for (i = 0; i < N; i++) {
                if (obj[i].Cost < 500) {
                    obj1[enter].Cost = obj[i].Cost;
                    obj1[enter].Title = obj[i].Title;
                    enter++; // Increment the counter
                }
                else{
                    count++;
                }
            }
            if (enter > 0) {
                cout << "Books with cost less than 500:\n";
                for (i = 0; i < enter; i++) {
                    obj1[i].display();
                }
            } else {
                cout << "No books found with cost less than 500.\n";
                count++;
            }
            break;

            case 5:
            cout<<"Total No Of Books Is Less than 500 Is : "<<count;
            break;
             case 6: {
                int postion;
            postion = 0;

            for (i = 0; i < N; i++) {
                for (j = i + 1; j < N; j++) {
                    if (obj[i].Title == obj[j].Title) {
            
                        obj2[postion] = obj[j];
                        postion++;

                        for (int k = j; k < N - 1; k++) {
                            obj[k] = obj[k + 1];
                        }
                        N--; 
                        j--; 
                    }
                }
            }

            
            if (postion > 0) {
                cout << "Duplicate Books Found:\n";
                for (i = 0; i < postion; i++) {
                    obj2[i].display();
                }
            } else {
                cout << "No duplicate books found.\n";
            }
            break;
        }


        case 7:
            cout << "Exiting... Thank you!\n";
            break;

        default:
            cout << "Wrong Choice. Please try again.\n";
            break;
        }

    } while (ch != 7);

    return 0;
}

