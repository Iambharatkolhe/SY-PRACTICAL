#include<iostream>
using namespace std;

class Complex {
    float a_real, a_imaginary;
    float b_real, b_imaginary;
public:
    float temp_real;       
    float temp_imaginary; 

    Complex() {
        temp_real = 0;
        temp_imaginary = 0;
    }

  
    void accept_First() {
        cout << "Enter the real part of complex number a: ";
        cin >> a_real;
        cout << "Enter the imaginary part of complex number a: ";
        cin >> a_imaginary;
    }
    void accept_second(){
        
        cout << "Enter the real part of complex number b: ";
        cin >> b_real;
        cout << "Enter the imaginary part of complex number b: ";
        cin >> b_imaginary;
    }

    Complex operator + (Complex& c) {
        Complex result;
        result.temp_real = a_real + c.b_real;
        result.temp_imaginary = a_imaginary + c.b_imaginary;
        return result;
    }

    Complex operator - (Complex& c) {
        Complex result;
        result.temp_real = a_real - c.b_real;
        result.temp_imaginary = a_imaginary - c.b_imaginary;
        return result;
    }

    Complex operator * (Complex& c) {
        Complex result;
        result.temp_real = (a_real * c.b_real) - (a_imaginary * c.b_imaginary);
        result.temp_imaginary = (a_real * c.b_imaginary) + (a_imaginary * c.b_real);
        return result;
    }

    Complex operator / (Complex& c) {
        Complex result;
        float denominator = (c.b_real * c.b_real) + (c.b_imaginary * c.b_imaginary);
        if (denominator == 0) {
            cout << "Denominator is zero, division is not calculable.\n";
            return result;
        }
        result.temp_real = (a_real * c.b_real + a_imaginary * c.b_imaginary) / denominator;
        result.temp_imaginary = (a_imaginary * c.b_real - a_real * c.b_imaginary) / denominator;
        return result;
    }

    void displayResult(const string& operation) {
        if (temp_imaginary >= 0) {
            cout << operation << " result: " << temp_real << " + " << temp_imaginary << "i\n";
        } else {
            cout << operation << " result: " << temp_real << " - " << -temp_imaginary << "i\n";
        }
    }
};

int main() {
    Complex comp1, comp2, result;
    int ch;

    
    comp1.accept_First();  
    comp2.accept_second();

    do {
        cout << "Menu\n1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n5. Exit\n";
        cin >> ch;
        switch (ch) {
            case 1:
                result = comp1 + comp2;  
                result.displayResult("Addition");
                break;
            case 2:
                result = comp1 - comp2; 
                result.displayResult("Subtraction");
                break;
            case 3:
                result = comp1 * comp2;  
                result.displayResult("Multiplication");
                break;
            case 4:
                result = comp1 / comp2; 
                result.displayResult("Division");
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Wrong choice. Please try again.\n";
        }
    } while (ch != 5);

    return 0;
}
