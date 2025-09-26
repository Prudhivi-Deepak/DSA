// Your code goes here

#include <bits/stdc++.h>
using namespace std;

class Robot {
   private:
    string name;

   public:
    Robot(string name) : name(name) { }//this->name = name; }

    void performAction() { cout << name + " is performing an action." << endl; }

    class Arm {
       private:
        Robot& robot;
       public:
        Arm(Robot &robot) : robot(robot) {} //constructor
        void pickItem() { cout << robot.name + " arm picking an item." << endl; }
    };

    class Processor {
       public:
        static void process() {
            cout << "Processor analyzing the data." << endl;
        }
    };

    void
    manageSensors() {
        class LocalInnerClass {
           private:
            Robot& robot; // Reference to the outer class object
           public:
            LocalInnerClass(Robot& robot) : robot(robot) {}
            void sense() {
                cout << robot.name + " sensor detecting obstacles." << endl;
            }
        };

        // LocalInnerClass lic = new LocalInnerClass();
        LocalInnerClass lic(*this);
        lic.sense();
    }

    class Task {
    public:
        virtual void execute() = 0;
        virtual ~Task(){};
    };

    void executeTask() {
        // Task newtask = new Task(){
        class CustomTask: public Task{
            Robot& robot;
            // @Override
            public : 
            CustomTask(Robot& robot) : robot(robot) {}
            void execute() override{
                cout << robot.name + " executing a custom task." << endl;
            }
        } ;
        // newtask(*this);
        CustomTask newtask(*this);
        newtask.execute();
    }
};

// Please Do not change anything below, It is only for your reference.
/*

  // Below code demonstrates the Driver code and its working for the class
  'Robot'.

  int main() {
      string name;

      // Creating the object of the class Robot
      Robot robot(name);

      // Calling the performAction method of class Robot
      robot.performAction();

      // Using non-static inner class
      // creating the object of the inner class and calling its method pickItem
      Robot::Arm arm(robot);
      arm.pickItem();

      // Using static nested class
      // creating the object of the nested class and calling its method process
      Robot::Processor processor;
      processor.process();

      // Calling the method manageSensors that implements the local inner class
      // It then calls the sense method inside the manageSensors method to print
  the corresponding text robot.manageSensors();

      // Calling method executeTask that overrides the method execute which is
  implemented by the interface Task robot.executeTask();

      return 0;
  }

*/

/*

cout << robot.name << " is performing an action.";        // -> It is for
performAction method cout << robot.name << " arm picking an item.";            // ->
It is for pickItem method cout << "Processor analyzing the data.";            //
-> It is for process method cout << robot.name << " sensor detecting obstacles."; //
-> It is for sense method cout << robot.name << " executing a custom task.";        //
-> It is for execute method

*/
