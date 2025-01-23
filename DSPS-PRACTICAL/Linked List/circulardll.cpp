#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;
};

Node* get_data() {
    Node* newnode = new Node;
    cout << "Enter Data: ";
    cin >> newnode->data;
    newnode->next = NULL;
    newnode->prev = NULL;
    return newnode;
}

Node* circulardoubly() {
    Node *newnode, *temp, *head;
    head = NULL;

    for (int i = 0; i < 10; i++) {
        newnode = get_data();

        if (head == NULL) {
            // Initialize the head with the first node
            head = newnode;
            newnode->next=head;
            temp = newnode;
        } else {
            // Link the new node to the previous node
            temp->next = newnode;
            newnode->prev = temp;
            newnode->next=head;
            temp = newnode;
        }
    }

    return head;
}

void display(Node* head) {
    if (head == NULL) {
        cout << "No nodes available." << endl;
        return;
    }
    Node* temp = head;
    cout << "The doubly linked list is: ";
   do
   {
        cout<<temp->data<<"<->";
        temp=temp->next;
   } while (temp!=head);
   cout<<"Head";
   
}

int main() {
    Node* head = circulardoubly();
    display(head);        
    return 0;
}
