#include<iostream>
#include<cstring>
using namespace std;

int stack[20]; 
int top = -1;     

void push(char c) {
    if (top == 19) {
        cout << "Stack Overflow\n";
    } else {
        top++;
        stack[top] = c;  
    }
}


char pop() {
    if (top == -1) {
        cout << "Stack Underflow\n";
        return '\0'; 
    } else {
        return stack[top--];  
    }
}

int main() {
    char input[20];  
    int length;
    int isPalindrome = 1;  

    cout << "Enter The sentence: ";
    cin.getline(input, 20); 

    length = strlen(input); 


    for (int i = 0; i < length; i++) {
       
        if (input[i] >= 'A' && input[i] <= 'Z') {
            input[i] = input[i] + 32;
        }

    
        if (input[i] >= 'a' && input[i] <= 'z') {
            push(input[i]);
        }
    }


    for (int i = 0; i < length; i++) {
      
        if (input[i] >= 'a' && input[i] <= 'z') {
            if (pop() != input[i]) {
                isPalindrome = 0;
                break;
            }
        }
    }

 
    if (isPalindrome) {
        cout << "This is a palindrome" << endl;
    } else {
        cout << "This is not a palindrome" << endl;
    }

    return 0;
}
