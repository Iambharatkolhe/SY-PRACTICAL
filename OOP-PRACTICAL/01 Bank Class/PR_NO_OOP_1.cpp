#include <iostream>
#include <string>
using namespace std;

class bharat_kolhe_financial_services {
public:
    string Customer_Name[20];
    long long Customer_account_no[20];
    float Customer_current_balance[20];
    int N, i;

    void accept() {
        cout << "Enter the number of customers: ";
        cin >> N;
        for (i = 0; i < N; i++) {
            cout << "Enter Name of Customer " << (i + 1) << ": ";
            cin >> Customer_Name[i];
            cout << "Enter Account Number of Customer " << (i + 1) << ": ";
            cin >> Customer_account_no[i];
            cout << "Enter Current Balance of Customer " << (i + 1) << ": ";
            cin >> Customer_current_balance[i];
        }
    }

    void display() {
        for (i = 0; i < N; i++) {
            cout << "Customer Name: " << Customer_Name[i] << "\n";
            cout << "Account Number: " << Customer_account_no[i] << "\n";
            cout << "Current Balance: " << Customer_current_balance[i] << "\n\n";
        }
    }

    void withdraw() {
        long long temp_account_no;
        float withdraw_amount;
        bool found = false;

        cout << "Enter Account Number: ";
        cin >> temp_account_no;

        for (i = 0; i < N; i++) {
            if (Customer_account_no[i] == temp_account_no) {
                found = true;
                cout << "Enter Amount to Withdraw: ";
                cin >> withdraw_amount;

                if (Customer_current_balance[i] >= withdraw_amount) {
                    Customer_current_balance[i] -= withdraw_amount;
                    cout << "Withdrawal Successful! Remaining Balance: " 
                         << Customer_current_balance[i] << "\n";
                } else {
                    cout << "Insufficient Balance!\n";
                }
                break;
            }
        }

        if (!found) {
            cout << "Account Not Found!\n";
        }
    }

    void credit() {
        long long temp_account_no;
        float credit_amount;
        bool found = false;

        cout << "Enter Account Number: ";
        cin >> temp_account_no;

        for (i = 0; i < N; i++) {
            if (Customer_account_no[i] == temp_account_no) {
                found = true;
                cout << "Enter Amount to Credit: ";
                cin >> credit_amount;

                Customer_current_balance[i] += credit_amount;
                cout << "Amount Credited! Updated Balance: " 
                     << Customer_current_balance[i] << "\n";
                break;
            }
        }

        if (!found) {
            cout << "Account Not Found!\n";
        }
    }
};

int main() {
    int choice;
    bharat_kolhe_financial_services obj;

    obj.accept();

    do {
        cout << "\nMenu:\n1. Display\n2. Withdraw\n3. Credit\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            obj.display();
            break;
        case 2:
            obj.withdraw();
            break;
        case 3:
            obj.credit();
            break;
        case 4:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid Choice! Try Again.\n";
        }
    } while (choice != 4);

    return 0;
}
