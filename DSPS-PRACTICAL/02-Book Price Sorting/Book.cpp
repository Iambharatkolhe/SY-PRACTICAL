#include <iostream>
using namespace std;

class NBook
{
public:
    int cost;
    string title;

    // Function to accept book details from the user
    void accept()
    {
        cout << "Enter the Title of the book: ";
        cin >> title;  // Accept the title of the book
        cout << "Enter the book cost: ";
        cin >> cost;  // Accept the cost of the book
        cout << "\n\n";
    }

    // Function to display the details of a book
    void display()
    {
        cout << "You entered book title: " << title << "\n";
        cout << "You entered book cost: " << cost << "\n\n";
    }
};

int main()
{
    int ch, n = 0, i, j, count;
    NBook temp;  // Temporary object used for swapping during sorting
    NBook obj[20], obj1[20];  // Arrays to store book details, increased size to allow for more books

    // Initial input for the number of books
    cout << "Enter the number of books you want to start with: ";
    cin >> n;

    do
    {
        // Display menu options
        cout << "\nMenu\n1. Accept\n2. Display\n3. Sort\n4. Display Books Less than 500\n5. Books Having Price Greater Than 500\n6. Exit\n";
        cin >> ch;  // Accept user choice

        switch (ch)
        {
        case 1:
            // Case 1: Add new books
            int newBooks;
            cout << "How many books do you want to add? ";
            cin >> newBooks;

            // Accept details for each new book
            for (i = n; i < n + newBooks; i++)
            {
                obj[i].accept();
            }
            n += newBooks;  // Update total number of books
            break;

        case 2:
            // Case 2: Display all books
            for (i = 0; i < n; i++)
            {
                obj[i].display();
            }
            break;

        case 3:
            // Case 3: Sort books by cost in descending order
            for (i = 0; i < n - 1; i++)
            {
                for (j = i + 1; j < n; j++)
                {
                    if (obj[i].cost < obj[j].cost)
                    {
                        temp = obj[i];
                        obj[i] = obj[j];
                        obj[j] = temp;  // Swap books to sort
                    }
                }
            }
            cout << "Books sorted by cost (descending order):\n";
            for (i = 0; i < n; i++)
            {
                obj[i].display();  // Display sorted books
            }
            break;

        case 4:
            // Case 4: Display books with cost less than 500
            count = 0;
            j = 0;

            // Check each book's cost
            for (i = 0; i < n; i++)
            {
                if (obj[i].cost < 500)
                {
                    obj1[j] = obj[i];  // Store books with cost less than 500
                    j++;
                }
                else
                {
                    count++;  // Count books with cost more than or equal to 500
                }
            }

            if (j > 0)
            {
                cout << "Books with cost less than 500:\n";
                for (i = 0; i < j; i++)
                {
                    obj1[i].display();  // Display books with cost less than 500
                }
            }
            else
            {
                cout << "No books with cost less than 500.\n";
            }
            break;

        case 5:
            // Case 5: Count and display the number of books with cost greater than 500
            count = 0;
            for (i = 0; i < n; i++)
            {
                if (obj[i].cost > 500)
                {
                    count++;  // Increment count for books costing more than 500
                }
            }
            cout << "Number of books with price greater than 500: " << count << endl;
            break;

        case 6:
            // Case 6: Exit the program
            cout << "Exiting... Thank you!\n";
            break;

        default:
            // Default case: Handle invalid menu options
            cout << "Invalid choice. Please enter again...\n";
        }
    } while (ch != 6);  // Loop until the user chooses to exit
    return 0;
}

   
