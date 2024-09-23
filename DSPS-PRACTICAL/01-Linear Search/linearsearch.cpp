#include <iostream>
using namespace std;

int main() {
    int a[10], n,temp,i,target,flag=0;
    
    cout << "Enter the size of an array: ";
    cin >> n;
    
    cout << "\nEnter the  array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(a[j]>a[j+1]){
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
    cout<<"The sorted array is!";
    for(i=0;i<n;i++){
        cout<<a[i]<<"\n";
    }
    cout<<"Enter the Target";
    cin>>target;
    for(i=0;i<n;i++){
        if(a[i]==target){
          flag=1;
          break;
        }
    
    }
    if(flag){
      cout<<"Elements"<<"\t"<<target<<"\t"<<"found at"<<"\t"<<i<<"\t"<<"position";
    }
     else{
            cout<<"Elements not Found";
        
        }
        return 0;
}