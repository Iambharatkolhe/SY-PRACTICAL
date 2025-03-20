#include<iostream>
using namespace std;
class Node{
    public:
    int vertics;
    Node *next;
    int MAT[10][20];
    Node(int val){
        vertics=val;
        next=NULL;

        for(int i=0;i<vertics;i++){
            for(int j=0;j<vertics;j++){
                MAT[i][j]=0;
            }
            
        }


    }  
    void add_edge(int source,int destinastion ,int we)
    { 
         for(int i=0;i<vertics;i++){
            for(int j=0;j<vertics;j++){
                MAT[source][destinastion]=1;
            }
         }

    }
      void dispaly(){
        for(int i=0;i<vertics;i++){
            for(int j=0;j<vertics;j++){
               cout<< MAT[i][j];
            }cout<<"\n";
         } 
      }
};

int  main(){

    Node obj(5);
    obj.add_edge(1 ,2, 3);
    obj.add_edge(0 ,3, 5);
    obj.add_edge(0 ,5, 9);
    obj.add_edge(2 ,3, 7);
    obj.add_edge(1 ,5, 3);
    obj.dispaly();
}
