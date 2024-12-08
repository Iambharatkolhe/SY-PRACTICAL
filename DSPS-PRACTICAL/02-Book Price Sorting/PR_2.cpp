#include<iostream>
using namespace std;
class book{
   public:
   int cost;
   string title,author;
   void accept(){
    cout<<"Enter The title of book: ";
    cin>>title;
    cout<<"Enter Book author: ";
    cin>>author;
    cout<<"Enter book Cost: ";
    cin>>cost;
   }
   void display(){
        cout<<"The Title of This Book is: "<<title<<"\n\n";
        cout<<"The Author of the book is: "<<author<<"\n\n";
        cout<<"The cost of the this book is: "<<cost<<"\n\n";

   }
};
int main(){
    int ch,N,i;
        int dub=0;
         int temp=0;
         int flag=0;
  book obj[20],obj1[20];
  cout<<"Enter Size Of array";
  cin>>N;
    do
    {
     cout<<"\n1.Accept\n2.Dispaly\n3.sort\n4.Display grater than 500\n5.dispaly less than 500\n6.Dublicate\n7.Exit";
     cin>>ch;
     switch (ch)
     {
     case 1:
        for(i=0;i<N;i++){
            obj[i].accept();
        }
        break;
        case 2:
        for(i=0;i<N;i++){
            obj[i].display();
        }
        break;
         case 3:
        for(i=0;i<N-1;i++){
           for(int j=i+1;j<N;j++){
            if(obj[i].cost > obj[j].cost){
               
                    book temp=obj[j];
                    obj[j]=obj[i];
                    obj[i]= temp;
            }
           }
        }
        cout<<"sorted list is: ";
        for(i=0;i<N;i++){
            obj[i].display();
        }
        break;
        case 4:
        for(i=0;i<N;i++){
            if(obj[i].cost > 500){
                obj[i].display();
            }
        }
        break;
          case 5:
          flag=0;
        for(i=0;i<N;i++){
            if(obj[i].cost < 500){
                flag=1;
            
                obj[i].display();
            }
        }
        if(flag==0){
           cout<<"No Less Than 500 Book found\n\n";
        }
        break;
         case 6:
         flag=0;
        for(i=0;i<N-1;i++){
            for(int j=i+1;j<N;j++){
                    if(obj[i].author==obj[j].author){
                        flag=1;
                       obj[i].display();
                    }
            }
            
            }
        if(flag==0){
           cout<<"No Less Than 500 Book found\n\n";
        }
        break;
        case 7:
        cout<<"Exiting....";
     default:
     cout<<"Wrong choice";
        break;
     }
    } while (ch!=7);
    return 0;
}