// Your code goes here

#include <bits/stdc++.h>
using namespace std;

class Counter{
public:
    static int count;

    Counter(){
        count++;
    }

    static int getCount(){
        return count;
    }

    static void resetCount(){
        count = 0;
    }

};

int Counter::count=0;


// Please Do not change anything below, It is only for your reference.
/*

This is the driver code that will execute and demonstrate the functionality of your `Counter` class.

It creates objects of class `Counter`. The default constructor increments the `count` variable each time an object is created.
At the end, we simply call the `getCount` method to print the total number of objects instantiated.


// Main function to demonstrate the functionality of the Counter class
int main() {

    // Create an input stream to take input from the user
    int count;
    std::cin >> count;

    while (count-- > 0) {
        Counter obj; // Create Counter objects
    }

    std::cout << "Number of objects created : " << Counter::getCount() << std::endl;

    return 0;
}

*/
