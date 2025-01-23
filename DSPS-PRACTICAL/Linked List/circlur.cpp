#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

Node* get_data() {
    Node* newnode = new Node;
    cout << "Enter Data: ";
    cin >> newnode->data;
    newnode->next = NULL;
    return newnode;
}

Node* circular() {
    Node *newnode, *temp, *head;
    head = NULL;

    for (int i = 0; i < 10; i++) {
        newnode = get_data();

        if (head == NULL) {
            head = newnode;
            temp = newnode;
            newnode->next = head; 
        } else {
            temp->next = newnode;
            temp = newnode;
            newnode->next = head; 
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
    cout << "The circular linked list is: ";
    do {
        cout << temp->data << " -> ";
        temp = temp->next;
    } while (temp != head); 
    cout << "(back to head)" << endl;
}


int main() {
    Node* head = circular();
    display(head);        
    return 0;
}
