#include <iostream>
#include <string>
using namespace std;

class car
{
public:
    string brand; // Attributes;
    string model;
    int number;

    car() // Constractor -name is similar as the class name
    {
        cout << "I am a constractor \n";
    }
    void insideMethod() // methods/functions
    {
        cout << "\n I am a method inside a class\n";
    }

    int outsideMethod(int x, int y);
};

// defining function outside the class
int car::outsideMethod(int x, int y)
{
    cout << "I am an outside method and the sum of the given numbers is:\n";
    return x + y;
}

// Encapsulation - accesing data from private class using public class
class myClass
{

private:
    int salary;

public:
    void SetSalary(int x)
    {
        salary = x;
    }

    int GetSalary()
    {
        return salary;
    }
};

//Multilevel Inheritance - Inheritance lets us inherit all the methods and attributes from another class
class parent //base class
{
public:
    void myFunctionParent()
    {
        cout << "I am the parent class \n";
    }
};

class child : public parent
{
};

class grandChild : public child
{
};

//Multiple Inheritance
class OneClass
{ //base class 1
public:
    void One_class()
    {
        cout << "I am the first base class\n";
    }
};

class AnotherClass
{ //base class 2
public:
    void Another_Class()
    {
        cout << "I am the second base class\n";
    }
};

class myChildClass : public OneClass, public AnotherClass
{ // merging all the base classes using ,(comma)
};

// protected class
class employee
{
protected:
    int sallary;
};

class acceser : public employee
{
public:
    void Set_Salary(int x)
    {
        sallary = x;
    }

    int Get_Salary()
    {
        return sallary;
    }
};

//polymorphism - when there are more similar classes which are related to each other by inheritance, polymorphism occers.Inheritance lets us inherit all the methods and attributes from another class, Polymorphism uses thoses methods to perform differnt tasks. This allows us to perform a single action in different ways.

class bike
{
public:
    void bike_avg()
    {
        cout << "All bikes have average of 50km per litter of gas\n";
    }
};

class R15 : public bike
{
public:
    void bike_avg()
    {
        cout << "R15 gives average of 51km per litter of gas\n";
    }
};

class Yamaha : public bike
{
public:
    void bike_avg()
    {
        cout << "Yamaha gives average of 30km per litter of petrol and gas\n";
    }
};

int main()
{

    car obj; // creating object using the created class
    myClass obj_1;
    obj_1.SetSalary(500000); // accesing private class using public class within the same class - encapulation
    cout << "salary is:" << obj_1.GetSalary();
    obj.insideMethod();              // accesing method from a public class
    cout << obj.outsideMethod(5, 6); // accesing method, which is defined outside the class, from a public class
    obj.brand = "\n BMW \n";         // appending sting value to its respective class attributes.
    cout << obj.brand;

    grandChild myObj;         // creating object using the created class
    myObj.myFunctionParent(); // Multilevel inheritance - method is actualy in the parent class, but due to inheritance, we can access the same class from its child or grandchild class.

    myChildClass myObj_1;    // creating object using the created class
    myObj_1.One_class();     // Multiple inheritance
    myObj_1.Another_Class(); // Multiple inheritance

    acceser myObj_2;           // creating object using the created class
    myObj_2.Set_Salary(10000); // accesing protected class method using inheritance
    cout << "the salary from inheritated protected class is:" << myObj_2.Get_Salary() << "\n";

    bike bike_1;
    R15 R15_1;
    Yamaha yamaha_1;

    bike_1.bike_avg(); // Polymorphism
    R15_1.bike_avg();
    yamaha_1.bike_avg();
    return 0;
}
