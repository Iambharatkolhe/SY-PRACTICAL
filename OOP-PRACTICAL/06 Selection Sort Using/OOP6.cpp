#include <iostream>
using namespace std;

template <typename T>
void sortArray(T a[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (a[i] > a[j]) {
                T temp = a[i]; 
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

template <typename T>
void displayArray(T a[], int size) {
    for (int i = 0; i < size; i++) {
        cout << a[i] << " ";
    }
    cout << endl; 
}

int main() {
  
    int a[] = {2, 6, 4, 1, 3};
    double a1[] = {2.6, 4.2, 5.2, 9.1, 4.1};
    char a2[] = {'a', 'z', 'b', 'c', 'e'};

   
    sortArray(a, 5);
    sortArray(a1, 5);
    sortArray(a2, 5);

    displayArray(a, 5);
    displayArray(a1, 5);
    displayArray(a2, 5);

    return 0;
}
