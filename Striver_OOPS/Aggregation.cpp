// Your code goes here
#include <bits/stdc++.h>
using namespace std;

class Department{
public:
    string name;
    string id;

    Department(string name, string id):
    name(name), id(id)
    {
        // this->name = name;
        // this->id = id;
    }

    void displayDetails(){
        cout << "Department Name : " << this->name << endl;
        cout << "Department Id : " << this->id << endl;
    }
};

class Employee{
public:
    string name;
    int id;
    Department department;

    Employee(string name, int id, Department department) :
    name(name), id(id), department(department)
    {
        // this->name = name;
        // this->id = id;
        // this->department = department;
    }

    void displayDetails(){
        cout << "Employee Name : " << this->name << endl;
        cout << "Employee Id : " << this->id << endl;
        department.displayDetails();
    }
};


// Please Do not change anything below, It is only for your reference.
/*

This is the driver code that will execute and demonstrate the functionality of your class `Employee` and the class `Department`.

int main() {

    string E_name, D_name, D_id;
    int E_id;

    // creates an object of Department class with D_name and D_id as arguments
    Department department(D_name, D_id);

    // creates an object of Employee class with E_name, E_id, and department as arguments
    Employee employee(E_name, E_id, &department);

    // calls the display method using the employee object
    employee.displayDetails();

    return 0;
}

*/

/*
// Below is the output format

cout << "Employee Name : " << name << endl;
cout << "Employee Id : " << id << endl;
cout << "Department Name : " << name << endl;
cout << "Department Id : " << id << endl;

*/
