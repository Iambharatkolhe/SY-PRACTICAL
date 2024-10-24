#include <iostream>
using namespace std;

#define Max 50

int queue[Max];
int front = -1;
int rear = -1;

void add(int no)
{
    if (rear == Max - 1)
        cout << "Queue is full\n";
    else
    {
        if (front == -1)
            front = 0;
        rear++;
        queue[rear] = no;
        cout << "Element added: " << no << "\n";
    }
}

void delete_first_side()
{
    if (front == -1 || front > rear)
    {
        front = -1;
        rear = -1;
        cout << "Queue is empty\n";
    }
    else
    {
        cout << "Element deleted: " << queue[front] << "\n";
        front++;
        if (front > rear)
            front = rear = -1;
    }
}

void delete_last_side()
{
    if (rear == -1 || front > rear)
    {
        cout << "Queue is empty\n";
    }
    else
    {
        cout << "Element deleted: " << queue[rear] << "\n";
        rear--;
        if (rear < front)
            front = rear = -1;
    }
}

int main()
{
    int N, ch, no;
    cout << "Enter queue size: ";
    cin >> N;

    do
    {
        cout << "Menu\n1. Add Element\n2. Delete First Side\n3. Delete Last Side\n4. Exit\n";
        cin >> ch;

        switch (ch)
        {
        case 1:
            if (rear < N - 1)
            {
                cout << "Enter number: ";
                cin >> no;
                add(no);
            }
            else
            {
                cout << "Queue is full, cannot add more elements.\n";
            }
            break;

        case 2:
            delete_first_side();
            break;

        case 3:
            delete_last_side();
            break;

        case 4:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Wrong choice, please try again.\n";
            break;
        }
    } while (ch != 4);

    return 0;
}
