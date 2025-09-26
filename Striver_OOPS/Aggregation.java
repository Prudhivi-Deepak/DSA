package Striver_OOPS;

//Your code goes here

class Employee{
    String name;
    int id;
    Department department;

    Employee(String name, int id, Department department){
        this.name = name;
        this.id = id;
        this.department = department;
    }

    void displayDetails(){
        System.out.println("Employee Name : "+this.name);
        System.out.println("Employee Id : "+this.id);
        department.displayDetails();
    }

}

class Department{
    String name;
    String id;

    Department(String name, String id){
        this.name = name;
        this.id = id;
    }

    void displayDetails(){
        System.out.println("Department Name : "+this.name);
        System.out.println("Department Id : "+this.id);
    }
}


//Please Do not change anything below, It is only for your reference.
/*

This is the driver code that will execute and demonstrate the functionality of your class `Employee` and the class 'Department'.


public class Main {

    public static void main(String[] args) {
    
        Scanner sc = new Scanner(System.in);

        String E_name, D_name, D_id;
        int E_id;

        //creats a object of Department class with D_name, D_id as the arguments
        Department department = new Department(D_name, D_id);
        
        //creates a object of Employee class with E_name, E_id, department as the arguments
        Employee employee = new Employee(E_name, E_id, department);
        
        //calls the display method using the employee object
        employee.displayDetails();

        sc.close();
    }
}

*/

/*
//Below is the output format

System.out.println("Employee Name: " + name);
System.out.println("Employee Id: " + id);
System.out.println("Department Name: " + name);
System.out.println("Department Id: " + id);

*/