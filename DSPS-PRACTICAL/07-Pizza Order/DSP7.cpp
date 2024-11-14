#include<iostream>
using namespace std;

class Pizza {
   int front = -1;
   int rear = -1;
   int queue[20];
    int price;

public:
   void Calculate_price(char size, int quantity) {
     
      if (size == 'S') {
         price = quantity * 50; 
      } 
      else if (size == 'M') {
         price = quantity * 75; 
      }                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       
      else {
         price = quantity * 100; 
      }
      cout << "Price Of Your Order: " << price << endl;
   }

   void Enqueue(int order) {
      if (rear == 19) {
         cout << "Order list is full" << endl;
      } 
      else {
         if (front == -1) {
            front = 0;
         }
         rear++;
         queue[rear] = order;
         cout << "Order added: " << order << endl;
      }
   }

   void Dequeue() {
      if (front == -1 || front > rear) {
         cout << "No orders found" << endl;
      } 
      else {
         cout << "Cancelling the order: " << queue[front] << endl;
         front++;
      }
   }
};

int main() {
   int ch, quantity, N;
   char size;
   Pizza obj;

   cout << "How many customers are placing orders: ";
   cin >> N;

   do {
      cout << "\nMenu:\n1. Buy Order\n2. Accept Delivery\n3. Cancel Delivery\n4. Exit\n";
      cout << "Enter your choice: ";
      cin >> ch;

      switch (ch) {
         case 1:  
            for (int i = 0; i < N; i++) {
               cout << "Enter size of pizza (S: Small, M: Medium, L: Large): ";
               cin >> size;
               cout << "How many pizzas do you want: ";
               cin >> quantity;
               obj.Enqueue(quantity);   
               obj.Calculate_price(size, quantity);
            }
            break;

         case 2:  
            cout << "Delivery accepted" << endl;
            break;

         case 3:  
            obj.Dequeue();
            break;

         case 4: 
            cout << "Exiting the program..." << endl;
            break;

         default:
            cout << "Invalid choice. Please try again." << endl;
      }
   } while (ch != 4);

   return 0;
}
