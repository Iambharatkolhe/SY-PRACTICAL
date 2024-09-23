#include <iostream>
#include<ctime>
using namespace std;
int main() {
    int a[10], n,temp,i,target,flag=0;
    clock_t start,end;
    cout << "Enter the size of an array: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
         cout << "Enter the "<<i+1<<" array elements: ";
        cin >> a[i];
    }
    cout<<"The array is";
    for(i=0;i<n;i++){
        cout<<"|"<<a[i]<<"|";
    }
    cout<<"\n Enter the Target :";
    cin>>target;
    start=clock();
    for(i=0;i<n;i++){
        if(a[i]==target){
          flag=1;
          cout<<"Elements Index at "<<i+1<<"  elements is:"<<a[i];
          break;
        }
    }
    for(i=n;i>0;i--){
        if(a[i]==target){
            flag=1;
        cout<<"\nElements Index at "<<i+1<<"  elements is:"<<a[i];
            break;
        }
    }
    if(flag==0){
        cout<<"Element Not Found";
    }
    end = clock();
    cout<<"\n Time taken is "<<double(end-start)/CLOCKS_PER_SEC<<" seconds"<<endl;
    return 0;
}