#include<iostream>
using namespace std;

class Engineer{
    public:
    string specilization;

    void work(){
        cout << "I have specialization in " << specilization << endl;
    }
};

class Youtuber{
    public:
    int subscribers;

    void contentcreator(){
        cout << "I have a subscriber base of " << subscribers << endl;
    }
};

class CodeTeacher: public Engineer, public Youtuber{
    public:
    string name;

    CodeTeacher(string name, string specilization, int subscribers){
        this->name = name;
        this->specilization = specilization;
        this->subscribers = subscribers;
    }

    void showcase(){
        cout << "My name is " << name << endl;
        work();
        contentcreator();
    }
};

int main(){
    CodeTeacher A1("Rohit", "CSE", 49000);
    A1.showcase();
}

/*
// To check which constructor run first
#include<iostream>
using namespace std;

class Engineer{
    public:
    string specilization;

    Engineer(){
        cout << "Hello Engineer\n";
    }

    void work(){
        cout << "I have specialization in " << specilization << endl;
    }
};

class Youtuber{
    public:
    int subscribers;

    Youtuber(){
        cout << "Hello Youtuber\n";
    }

    void contentcreator(){
        cout << "I have a subscriber base of " << subscribers << endl;
    }
};

class CodeTeacher: public Engineer, public Youtuber{ // if here I write line like this class CodeTeacher: public Youtuber, public Engineer then output changes. As first Youtuber then Engineer and atlast CodeTeacher Constructor will run
    public:
    string name;

    CodeTeacher(){
        cout << "Hello Coder\n";
    }

    void showcase(){
        cout << "My name is " << name << endl;
        work();
        contentcreator();
    }
};

int main(){
    CodeTeacher A1;
}
*/
