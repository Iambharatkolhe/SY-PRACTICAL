#include<iostream>
using namespace std;

class Bharat_Kolhe_Financial_Services{
public:
    char name[20];
    
    long Account_no;
    float Current_Balance;
    float Withdraw_amount;
    float Deposit_amount;

    void accept() {
        cout << "Enter Your Name: ";
        cin >> name;
        cout << "Enter Your Account no: ";
        cin >> Account_no;
        cout << "Enter Current Balance: ";
        cin >> Current_Balance;
    }

    void display() {
        cout << "Your Name is: " << name;
        cout << "\nYour Account no is: " << Account_no;
        cout << "\nYour Current Balance is: " << Current_Balance<<"\n";
    }

    void withdraw() {
        cout << "Enter Withdrawal amount: ";
        cin >> Withdraw_amount;
        if (Withdraw_amount > Current_Balance) {
            cout << "Insufficient balance." << endl;
        } else {
            Current_Balance -= Withdraw_amount;
            cout << "Withdrawal successful. New balance: " << Current_Balance << endl;
        }
    }

    void deposit() {
        cout << "Enter Deposit amount: ";
        cin >> Deposit_amount;
        Current_Balance += Deposit_amount;
        cout << "Deposit successful. New balance: " << Current_Balance << endl;
    }
};

int main() {
    int choice,n,i,aco,flag=0;
    Bharat_Kolhe_Financial_Services BKFS1;
    Bharat_Kolhe_Financial_Services obj[10];
    cout<<"Enter How many User:";
    cin>>n;
    do {
        cout << "\n1. Accept Info\n2. Display Info\n3. Withdraw amount\n4. Deposit amount\n5. Exit\n";
        cin >> choice;

        switch (choice) {
        case 1:
        for(i=0;i<n;i++){
            obj[i].accept();
        }
            break;
        case 2:
        for ( i = 0; i < n; i++)
        {
              obj[i].display();

        }
            break;
        case 3: 
        cout<<"Enter Bank account number For Widraw";
        cin>>aco;
        for(i=0;i<n;i++){ 
          if(obj[i].Account_no==aco){
            obj[i].withdraw();
             break;
          }  
        
        } 
          if(i==n){
            cout<<"Wrong Accound No / User Not Found";
          }
          break;
        
        case 4:
          cout<<"Enter Bank account number For Widraw";
        cin>>aco;
        for(i=0;i<n;i++){ 
          if(obj[i].Account_no==aco){
            obj[i].deposit();
            break;
          }  
        
        } 
          if(i==n){
            cout<<"Wrong Accound No / User Not Found";
          }
          break;
        
        case 5:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Wrong Choice" << endl;
            break;
        }
    
    } while (choice != 5);

    return 0;
}
