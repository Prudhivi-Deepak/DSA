#include <bits/stdc++.h>
using namespace std;

//Your code goes here

class Animal{
protected:
    string name;
public:
    Animal(string name) : name(name){
        // this->name = name;
    }

    virtual void makeSound() = 0;
};

class Dog : public Animal{
public:
    Dog(string name): Animal(name){
        // super(name);
    }

    // @Override
    void makeSound() override{
        cout << "The dog " << this->name << " says : Woof!" << endl;
    }
};

class Cat : public Animal{
public:
    Cat(string name) : Animal(name){
        // super(name);
    }

    // @Override
    void makeSound() override{
        cout << "The cat " << this->name << " says : Meow!" << endl;
    }
};


//Please Do not change anything below, It is only for your reference.
/*

This is the driver code that will execute and demonstrate the functionality of your abstract class `Animal` and the derived classes 'Dog', 'Cat'.

First, the object of the class Dog is created along with the dog name.
Then the Dog class object is used to call the method makeSound() to print the corresponding text of Dog class.

Next, the object of the class Cat is created along with the cat name.
Then the Cat class object is used to call the method makeSound() to print the corresponding text of Cat class.


int main() {

    // Input names for dog and cat
    string dName, cName;
    getline(cin, dName);
    getline(cin, cName);

    // Create Dog object
    Animal* dog = new Dog(dName);
    dog->makeSound();

    // Create Cat object
    Animal* cat = new Cat(cName);
    cat->makeSound();

    // Clean up
    delete dog;
    delete cat;

    return 0;
}

*/


/*
//Below are the output statements

cout << "The dog " << name << " says : Woof!" << endl;
cout << "The cat " << name << " says : Meow!" << endl;

*/
