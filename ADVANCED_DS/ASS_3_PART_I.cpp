#include<iostream>
using namespace std;
class graph{
    public:
    int i,j,Vertices;
    int MAT[10][10];
    graph(int V){
        Vertices=V;
        for(i=1;i<=V;i++){
            for(j=1;j<=V;j++){
              MAT[i][j]=0;
            }
        }

    }
    void ADD_EDGE(int S,int D,int we){
          MAT[S][D]=we;
    }

    void display(){
        for(i=1;i<=Vertices;i++){
            cout<<"\t\t | \t";
            for(j=1;j<=Vertices;j++){
              cout<<MAT[i][j]<<"\t";
            }

        cout<<"|\n";
        }

}
};
int main(){
  

   graph obj(5);
   
   obj.ADD_EDGE(1,1,5);
   obj.ADD_EDGE(2,3,6);
   obj.ADD_EDGE(5,1,7);
   obj.ADD_EDGE(5,1,8);

   obj.ADD_EDGE(3,4,9);
   obj.ADD_EDGE(4,5,7);
  
   obj.display();

   return 0;

}