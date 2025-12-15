#include<iostream>
using namespace std;
/*
NOTE:-
Virtual base classes are used in virtual inheritance in a way of preventing multiple "instances" of a given class appearing in an inheritance hierarchy when using multiple inheritances.

Consider the situation where we have one class A . This class A is inherited by two other classes B and C. Both these class are inherited into another in a new class D. The data members/function of class A are inherited twice to class D. One through class B and second through class C. When any data / function member of class A is accessed by an object of class D, ambiguity arises as to which data/function member would be called? One inherited through B or the other inherited through C. This confuses compiler and it displays error.
How to resolve this issue? 
To resolve this ambiguity when class A is inherited in both class B and class C, it is declared as virtual base class by placing a keyword virtual.
virtual can be written before or after the public. Now only one copy of data/function member will be copied to class C and class B and class A becomes the virtual base class. Virtual base classes offer a way to save space and avoid ambiguities in class hierarchies that use multiple inheritances. When a base class is specified as a virtual base, it can act as an indirect base more than once without duplication of its data members. A single copy of its data members is shared by all the base classes that use virtual base.  
*/
class Human{
    public:
    string name;

    void display(){
        cout << "My name is " << name << endl;
    }
};

class Engineer : public virtual Human{
    public:
    string specilization;

    void work(){
        cout << "I have specialization in " << specilization << endl;
    }
};

class Youtuber : public virtual Human {
    public:
    int subscribers;

    void contentcreator(){
        cout << "I have a subscriber base of " << subscribers << endl;
    }
};

class CodeTeacher: public Engineer, public Youtuber{ // if here I write line like this class CodeTeacher: public Youtuber, public Engineer then output changes. As first Youtuber then Engineer and atlast CodeTeacher Constructor will run
    public:
    int salary;

    CodeTeacher(){

    }

    CodeTeacher(string name, string specilization, int subscribers, int salary){
        this->name = name;
        this->specilization = specilization;
        this->subscribers = subscribers;
        this->salary = salary;
    }
};

int main(){
    CodeTeacher A1("Rohit", "CSE", 49000, 99);
    A1.display();
}