#include<iostream>
using namespace std;
class studentdatabase{
    public:
    string name,contact_address,blood_group;
    double date_of_birth,Insurance_Policy_Number,Telephone_Number,Driving_Licence_No;
    float hight,weight;
    void accept(){
        cout<<"Enter Your Name";
        cin>>name;
        cout<<"Enter Your Contact Addrease";
        cin>>contact_address;
        cout<<"Enter Blood Group";
        cin>>blood_group;
        cout<<"Enter Data Birth";
        cin>>date_of_birth;
        cout<<"Enter Ensurance Policty Number";
        cin>>Insurance_Policy_Number;
        cout<<"Enter Telephone number";
        cin>>Telephone_Number;
        cout<<"Enter Driving Licence Number";
        cin>>Driving_Licence_No;
    }
        studentdatabase() {
               int data;
               cout<<"Eterate First";
        }
        studentdatabase(){
            int sap;
            cout<<"Eterate second";
        }

    };


    studentdatabase obj;
/*Develop an object oriented program in C++ /Python to create a
database of the personnel information system containing the following
information: Name, Date of Birth, Blood group, Height, Weight,
Insurance Policy number, Contact address, telephone number, driving
licence no. etc Construct the database with suitable member functions
for initializing and destroying the data viz constructor, default
constructor, copy constructor, destructor, static member functions ,
friend class, this pointer, inline code and dynamic memory allocation
operators-new and delete.*/