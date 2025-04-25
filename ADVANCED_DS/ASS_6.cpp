#include<iostream>
#include<iomanip>
using namespace std;

class hashing {
public:
    int check[20];     
    int stored[20];
    int size_Of_Hash_Table;
                           
    hashing(int hashingsize) {
        size_Of_Hash_Table = hashingsize;
        for (int i = 0; i < hashingsize; i++) {
            check[i] = 0; 
        }
    }

    void add_hash_value(int value) {
        int hash_index = value % size_Of_Hash_Table;
        cout << "Hash Value is : " << value << " And Initial Hash Key is : " << hash_index << "\n";
    
        int flag = 0;
        int count = 0;
    
        for (int i = 0; i < size_Of_Hash_Table; i++) {
            if (check[i] != 0) {
                count++;
            }
        }
    
        if (count == size_Of_Hash_Table) {
            cout << "Hash table is full\n";
            return;
        }
    
        int original_index = hash_index;
    
        while (flag != 1) {
            if (check[hash_index] == 0 || check[hash_index] == -1) {
                flag = 1;
                check[hash_index] = 1;
                stored[hash_index] = value;
                if (hash_index != original_index) {
                    cout << "Collision occurred at index " << original_index << ", ";
                    cout << "but value inserted at index " << hash_index << "\n";
                } else {
                    cout << "Value inserted at index " << hash_index << "\n";
                }
            } else {
                if (hash_index == original_index) {
                    cout << "Collision occurred at index " << hash_index << "\n";
                }
                hash_index++;
                if (hash_index == size_Of_Hash_Table) {
                    hash_index = 0;
                }
            }
        }
    }
    

    void display() {
        cout << "\n" << setw(15) << "INDEX" << setw(20) << "STORED VALUE" << "\n";
        cout << "----------------------------------------\n";
        for (int i = 0; i < size_Of_Hash_Table; i++) {
            cout << setw(15) << i;
            if (check[i] == 1) {
                cout << setw(20) << stored[i] << "\n";
            } else if (check[i] == -1) {
                cout << setw(20) << "DEL\n";
            } else {
                cout << setw(20) << "MT\n";
            }
        }
    }

    void update(int pre_value, int after_value) {
        int index = pre_value % size_Of_Hash_Table;
        int start_index = index;
        
        while (check[index] != 0) {
            if (check[index] == 1 && stored[index] == pre_value) {
                stored[index] = after_value;
                cout << "\nElement updated successfully.\n";
                return;
            }
            index++;
            if(index==size_Of_Hash_Table){
                index=0;
            }
            if (index == start_index) break;
        }
        cout << "\nElement not found. Please enter a valid number.\n";
    }

    void delete_no(int number) {
        int index = number % size_Of_Hash_Table;
        int start_index = index;

        while (check[index] != 0) {
            if (check[index] == 1 && stored[index] == number) {
                check[index] = -1;
                cout << "\nElement " << number << " deleted successfully.\n";
                return;
            }
            else{
                   index++;
                if(index==size_Of_Hash_Table){
                    index=0;
                }
            }
             if (index == start_index) break;
        }
        cout << "\nElement not found. Please enter a valid number.\n";
    }

    void search(int number) {
        int index = number % size_Of_Hash_Table;
       int start_index=index;
        while (check[index] != 0) {
            if (check[index] == 1 && stored[index] == number) {
                cout << "\nElement " << number << " found at index " << index << ".\n";
                return;
            }
             else{
                index++;

                if(index==size_Of_Hash_Table){
                    index=0;
                }
             }
            if (index == start_index) break;
        }
        cout << "\nElement " << number << " not found in hash table.\n";
    }
};

int main() {
    int size;
    cout << "Enter Total Size Of Hashing Table: ";
    cin >> size;

    hashing obj(size);

    int choice, value, old_val, new_val;
    do {
        cout << "\n----- MENU -----\n";
        cout << "1. Insert\n";
        cout << "2. Display\n";
        cout << "3. Update\n";
        cout << "4. Delete\n";
        cout << "5. Search\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to insert: ";
            cin >> value;
            obj.add_hash_value(value);
            break;
        case 2:
            obj.display();
            break;
        case 3:
            cout << "Enter existing value to update: ";
            cin >> old_val;
            cout << "Enter new value: ";
            cin >> new_val;
            obj.update(old_val, new_val);
            break;
        case 4:
            cout << "Enter value to delete: ";
            cin >> value;
            obj.delete_no(value);
            break;
        case 5:
            cout << "Enter value to search: ";
            cin >> value;
            obj.search(value);
            break;
        case 0:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice! Please try again.\n";
        }

    } while (choice != 0);

    return 0;
}
