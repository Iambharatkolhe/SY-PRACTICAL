#include<iostream>
using namespace std;
int key,i,N;
int main(){
    int a[20];
    int flag=0;
    cout<<"Enter the length of array: ";
    cin>>N;
    for(i=0;i<N;i++){
    cout<<"Enter "<<i+1<<" Element: ";
    cin>>a[i];
    }
    cout<<"Enter the Kay element you want to find: ";
    cin>>key;
    for(i=0;i<N;i++){
        if(a[i]==key){
            flag=1;
            cout<<"\n\nElement found at "<<i+1<<" Location and element is "<<a[i]<<"\n\n";
            break;
    }
}
if(flag==0){
    cout<<"\n\nSorry no elment found\n";
}
return 0;
}