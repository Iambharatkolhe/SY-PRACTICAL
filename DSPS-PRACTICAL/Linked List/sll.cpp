#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node *next;
};
Node* get_data(){
    Node *newnode;
    newnode= new Node;
    cout<<"Enter Data :";
   cin>> newnode->data;
    newnode->next=NULL;

    return newnode;
}
Node* singlylist(){
    Node *newnode,*temp,*head;
    head=NULL;
   for(int i=0;i<10;i++){
        newnode=get_data();

        if(head==NULL){
            head=newnode;
            temp=newnode;
        }
        else{
            temp->next=newnode;
            newnode->next=NULL;
            temp=newnode;
        }
       
   }
  
  return head;
}
void disaply(Node *head){
    Node *temp;
    temp=head;
    
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL";
}
int main(){
   Node *head=singlylist();
  cout<<"The linked list is :\n";
   disaply(head);
return 0;
}
