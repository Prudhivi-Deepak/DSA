#include <bits/stdc++.h>
using namespace std;

// Your code goes here

class College{
public:
    string name, id;

    College(string name, string id){
        this->name = name;
        this->id = id;
    }

    void displayDetails(){
        cout << "College Name : "+this->name << endl;
        cout << "College ID : "+this->id << endl;
    }

};

class University{
public:
    string name;
    vector<College> colleges;

    University(string name){
        this->name = name;
        colleges.clear();
    }

    void addCollege(string collegeName, string collegeId){
        colleges.push_back(College(collegeName, collegeId));
    }

    void displayDetails(){
        cout << "University Name : "+this->name << endl;
        for(College c : colleges){
            c.displayDetails();
        }
    }

};

// Please Do not change anything below, It is only for your reference.
/*

This is the driver code that will execute and demonstrate the functionality of your class `University` and the class `College`.


int main() {

    // Input reading
    string name;
    vector<string> collegeName, collegeId;

    // Creating the object of class University with the name as constructor argument
    University university(name);

    // Adding the college names and IDs using the addCollege method called through the university object
    for (int j = 0; j < collegeName.size(); j++) {
        university.addCollege(collegeName[j], collegeId[j]);
    }

    // Calling the method displayDetails through the university object
    university.displayDetails();

    return 0;
}

*/

/*
// Below is the output format:

cout << "University Name : " << name << endl;
cout << "College Name : " << name << endl;
cout << "College ID : " << id << endl;

*/
