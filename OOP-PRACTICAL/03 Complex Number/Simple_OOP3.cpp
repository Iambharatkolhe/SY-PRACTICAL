#include<iostream>
using namespace std;
class Complex {
    float a_real, b_real;
    float a_imaginary, b_imaginary;
public:
    float temp_real;       
    float temp_imaginary; 
    
    Complex() {
        temp_real = 0;
        temp_imaginary = 0;
    }

    void accept() {
        cout << "Enter the real part of complex number a: ";
        cin >> a_real;
        cout << "Enter the imaginary part of complex number a: ";
        cin >> a_imaginary;

        cout << "Enter the real part of complex number b: ";
        cin >> b_real;
        cout << "Enter the imaginary part of complex number b: ";
        cin >> b_imaginary;
    }

    void addition() {
        temp_real = a_real + b_real;
        temp_imaginary = a_imaginary + b_imaginary;
        
        if (temp_imaginary >= 0) {
            cout << "Addition result: " << temp_real << " + " << temp_imaginary << "i\n";
        } else {
            cout << "Addition result: " << temp_real << " - " << -temp_imaginary << "i\n"; 
        }
    }

    void subtraction() {
        temp_real = a_real - b_real;
        temp_imaginary = a_imaginary - b_imaginary;
        
        if (temp_imaginary >= 0) {
            cout << "Subtraction result: " << temp_real << " + " << temp_imaginary << "i\n";
        } else {
            cout << "Subtraction result: " << temp_real << " - " << -temp_imaginary << "i\n"; 
        }
    }

    void multiplication() {
        temp_real = (a_real * b_real) - (a_imaginary * b_imaginary);
        temp_imaginary = (a_real * b_imaginary) + (a_imaginary * b_real);
        
        if (temp_imaginary >= 0) {
            cout << "Multiplication result: " << temp_real << " + " << temp_imaginary << "i\n";
        } else {
            cout << "Multiplication result: " << temp_real << " - " << -temp_imaginary << "i\n"; 
        }
    }

     void division() {
      
        float denominator = (b_real * b_real) + (b_imaginary * b_imaginary);
        
        if (denominator == 0) {
            cout << "Denominator is zero, division is not calculable.\n";
            return;
        }

        temp_real = (a_real * b_real + a_imaginary * b_imaginary) / denominator;
        temp_imaginary = (a_imaginary * b_real - a_real * b_imaginary) / denominator;

        if (temp_imaginary >= 0) {
            cout << "Division result: " << temp_real << " + " << temp_imaginary << "i\n";
        } else {
            cout << "Division result: " << temp_real << " - " << -temp_imaginary << "i\n"; 
        }
    }

};

int main() {
    Complex comp;
    int ch;
    do {
        cout << "Menu\n1. Accept\n2. Addition\n3. Subtraction\n4. Multiplication\n5. Division\n6. Exit\n";
        cin >> ch;
        switch (ch) {
            case 1:
                comp.accept();
                break;
            case 2:
                comp.addition();
                break;
            case 3:
                comp.subtraction();
                break;
            case 4:
                comp.multiplication();
                break;
            case 5:
                comp.division();
                break;
            case 6:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Wrong choice. Please try again.\n";
        }
    } while (ch != 6);

    return 0;
}
