#include <iostream>
using namespace std;

class Node {
public:
    int salary;
    int employee_id;
    Node *left, *right;

    Node(int value, int id) {
        salary = value;
        employee_id = id;
        left = right = NULL;
    }
};

Node* insert(Node* root, int salary, int id) {
    if (root == NULL) {
        return new Node(salary, id);
    }
    if (salary < root->salary) {
        root->left = insert(root->left, salary, id);
    } else {
        root->right = insert(root->right, salary, id);
    }
    return root;
}

void search(Node* root, int key) {
    while (root != NULL) {
        if (root->salary == key) {
            cout << "Employee ID: " << root->employee_id << ", Salary: " << root->salary << endl;
            return;
        } else if (key < root->salary) {
            root = root->left;
        } else {
            root = root->right;
        }
    }
    cout << "Sorry, no employee found.\n";
}

void update(Node* root, int old_salary, int new_salary) {
    Node* temp = root;
    while (temp != NULL) {
        if (temp->salary == old_salary) {
            cout << "Before Update -> ID: " << temp->employee_id << ", Salary: " << temp->salary << endl;
            temp->salary = new_salary;
            cout << "After Update -> ID: " << temp->employee_id << ", Salary: " << new_salary << endl;
            return;
        } else if (old_salary < temp->salary) {
            temp = temp->left;
        } else {
            temp = temp->right;
        }
    }
    cout << "No employee found with salary " << old_salary << endl;
}

void display(Node* root) {
    if (root == NULL) return;
    display(root->left);
    cout << "Employee ID: " << root->employee_id << ", Salary: " << root->salary << endl;
    display(root->right);
}

int minSalary(Node* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root->salary;
}

int maxSalary(Node* root) {
    while (root->right != NULL) {
        root = root->right;
    }
    return root->salary;
}

int sumSalary(Node* root) {
    if (root == NULL) return 0;
    return root->salary + sumSalary(root->left) + sumSalary(root->right);
}

int countEmployees(Node* root) {
    if (root == NULL) return 0;
    return 1 + countEmployees(root->left) + countEmployees(root->right);
}

void computeAverageSalary(Node* root) {
    int totalSalary = sumSalary(root);
    int totalEmployees = countEmployees(root);
    if (totalEmployees > 0) {
        cout << "Average Salary: " << (totalSalary / totalEmployees) << endl;
    } else {
        cout << "No Employees Available.\n";
    }
}

int main() {
    Node* root = NULL;
    int choice, id, salary, old_salary, new_salary;

    do {
        cout << "\nEmployee Management System\n";
        cout << "1. Create Employee\n2. Search Employee\n3. Update Salary\n4. Display Employees\n";
        cout << "5. Minimum Salary\n6. Maximum Salary\n7. Compute Average Salary\n8. Count Total Employees\n9. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Employee ID: ";
                cin >> id;
                cout << "Enter Salary: ";
                cin >> salary;
                root = insert(root, salary, id);
                break;
            case 2:
                cout << "Enter Salary to Search: ";
                cin >> salary;
                search(root, salary);
                break;
            case 3:
                cout << "Enter Current Salary: ";
                cin >> old_salary;
                cout << "Enter New Salary: ";
                cin >> new_salary;
                update(root, old_salary, new_salary);
                break;
            case 4:
                cout << "Employees List (Sorted by Salary):\n";
                display(root);
                break;
            case 5:
                cout << "Minimum Salary: " << minSalary(root) << endl;
                break;
            case 6:
                cout << "Maximum Salary: " << maxSalary(root) << endl;
                break;
            case 7:
                computeAverageSalary(root);
                break;
            case 8:
                cout << "Total Number of Employees: " << countEmployees(root) << endl;
                break;
            case 9:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid Choice! Try again.\n";
        }
    } while (choice != 9);

    return 0;
}
