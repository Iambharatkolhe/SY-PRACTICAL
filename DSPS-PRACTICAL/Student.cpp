#include<iostream>
using namespace std;
class Student
{
    public:
    char name[20];
    float Roll;

void accept(){
    cout<<"Enter Your Name:";
    cin>>name;
    cout<<"Enter Roll no:";
    cin>>Roll;
}
void display(){
 cout<<"Your Name is:"<<name;
 cout<<"\nYour Roll No is:"<<Roll;
}
};
int main(){
    int i;
   
    Student b1;
    do
    {
    cout<<"\n1.Accept Info\n2.Display Info\n3.Exit\n";
    cin>>i;
    
    switch (i)
    {
    case 1:
        b1.accept();
        break;
     case 2:
        b1.display();
        break;
    } 
 } while (i!= 3);
 return 0;
}