#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

class NBook
{
public:
    int cost, stock;
    string title, author, publisher;

    void accept() {
        cout << "Enter the Title of the book:";
        cin >> title;
        cout << "Enter Author Name: ";
        cin >> author;
        cout << "Enter the book cost: ";
        cin >> cost;
        cout << "Enter Publisher: ";
        cin >> publisher;
        cout << "Enter stock quantity: ";
        cin >> stock;
        cout << "\n";
    }

    // Function to display the details of a book in a tabular format
    void display() const {
        cout << "| " << setw(20) << left  << title
             << "| " << setw(20) << left  << author
             << "| " << setw(10) <<left  << cost
             << "| " << setw(20) << left  << publisher
             << "| " << setw(10) << left << stock << " |\n";
    }
};

int main()
{
    int ch, N = 0, i, j, Quantity;
    NBook temp;
    NBook obj[20];
    string temptitle, tempauthor;

    do
    {
        // Display menu options
        cout << "\nMenu\nI. Accept\nII. Display\nIII. Sort\nIV. Buy Book\nV. Exit\n";
        cin >> ch;  // Accept user choice

        switch (ch)
        {
        case 1:
            // Case 1: Add new books
            cout << "How many books do you want to add? ";
            cin >> N;

            // Accept details for each new book
            for (i = 0; i < N; i++) {
                obj[i].accept();
            }
            break;

        case 2:
            // Case 2: Display all books
            if (N == 0) {
                cout << "Firstly Enter The Stock: \n";
            } else {
                // Print table header with borders
                cout << "\n+------------------------------------------------------------------------------------------\n";
                cout << "| " << setw(20) << left  << "Title"
                     << "| " << setw(20) << left  << "Author"
                     << "| " << setw(10) << left  << "Cost"
                     << "| " << setw(20) << left << "Publisher"
                     << "| " << setw(10) << left << "Stock" << " |\n";
                cout << "+-----------------------------------------------------------------------------------------\n";

                // Print each book entry with borders
                for (i = 0; i < N; i++) {
                    obj[i].display();
                }

                // Print table footer with borders
                cout << "+------------------------------------------------------------------------------------------\n";
            }
            break;

        case 4:
            // Case 4: Buy a book
            cout << "Enter Book title: ";
            cin >> temptitle;
            cout << "Enter Book Author: ";
            cin >> tempauthor;

            for (i = 0; i < N; i++) {
                if (obj[i].title == temptitle  &&  obj[i].author == tempauthor) {
                    cout << "\n\n______Book is Available______\n\n";
                     cout << " Available Stock is: " << obj[i].stock <<"\n\n";
                   
                    cout<<"How Many Books do You Want: ";
                     cin >> Quantity;

                    if (obj[i].stock >= Quantity) {
                       
                        int c = Quantity * obj[i].cost;
                        obj[i].stock -= Quantity;
                        cout << "\n\nTotal Cost Of these Books Is: " << c << "\n\n";
                   
                    } else {
                        cout << "\n\nNot Enough Stock Available. \n";
                    }
                    break;
                }
            }

            if (i == N) {
                cout << "Book Not Found\n\n";
            }
            break;

        case 3:
            // Case 3: Sort books by cost in descending order
            for (i = 0; i < N - 1; i++) {
                for (j = i + 1; j < N; j++) {
                    if (obj[i].cost < obj[j].cost) {
                        temp = obj[i];
                        obj[i] = obj[j];
                        obj[j] = temp;  // Swap books to sort
                    }
                }
            }
            cout << "Books sorted by cost (descending order):\n";
            cout << "+------------------------------------------------------------------------------------------\n";
            cout << "| " << setw(20) << left << "Title"
                 << "| " << setw(20) <<left  << "Author"
                 << "| " << setw(10) <<left  << "Cost"
                 << "| " << setw(20) << left << "Publisher"
                 << "| " << setw(10) << left << "Stock" << " |\n";
            cout << "+------------------------------------------------------------------------------------------\n";

            for (i = 0; i < N; i++) {
                obj[i].display();
            }

            cout << "+------------------------------------------------------------------------------------------\n";
            break;

        case 5:
            // Case 5: Exit the program
            cout << "Exiting... Thank you!\n";
            break;

        default:
            // Default case: Handle invalid menu options
            cout << "Invalid choice. Please enter again...\n";
        }
    } while (ch != 5); 

    return 0;
}
