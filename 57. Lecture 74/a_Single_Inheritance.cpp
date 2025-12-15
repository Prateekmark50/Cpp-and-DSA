#include<iostream>
using namespace std;

class Human{
protected:
    string name;
    int age;

public:
    void work(){
        cout << "I am working\n";
    }
};

class Student: public Human{
    int roll_number, fees;

public:
    Student(string name, int age, int roll_number, int fees){
        this->name = name;
        this->age = age;
        this->roll_number = roll_number;
        this->fees = fees;
    }

    void display(){
        cout << name << " " << age << " " << roll_number << " " << fees << endl;
    }
};

int main(){
    Student A1("Rohit", 26, 32, 99);
    A1.work();
    A1.display();
}

// // Another Way to disolay code
// #include<iostream>
// using namespace std;

// class Human{
// protected:
//     string name;
//     int age;

// public:
//     Human(string name, int age){
//         this->name = name;
//         this->age = age;
//     }
// // NOTE:- Here I have created two display function.This display function will not run instead below display function in Student class will run. If there is no display function in Student class then this fuction will run.
//     void display(){
//         cout << name  << " " << age << endl;
//     }
    
//     void work(){
//         cout << "I am working\n";
//     }
// };

// class Student: public Human{
//     int roll_number, fees;

// public:
//     Student(string name, int age, int roll_number, int fees): Human(name, age){
//         this->roll_number = roll_number;
//         this->fees = fees;
//     }

//     void display(){
//         cout << name << " " << age << " " << roll_number << " " << fees << endl;
//     }
// };

// int main(){
//     Student A1("Rohit", 26, 32, 99);
//     A1.work();
//     A1.display();
// }


/*
// This below code tell how the constructor and destructor work in single inheritance
#include<iostream>
using namespace std;

class Human{
protected:
    string name;
    int age;

public:
    Human(){
        cout << "Hello Human Constructor\n";
    }
    ~Human(){
        cout << "Hello Human Destructor\n";
    }
};

class Student: public Human{
    int roll_number, fees;

public:
    Student(){
        cout << "Hello Student Constructor\n";
    }
    ~Student(){
        cout << "Hello Student Destructor\n";
    }
};

int main(){
    Student A1;
}
*/