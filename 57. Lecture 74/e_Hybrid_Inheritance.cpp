#include<iostream>
using namespace std;

class Student{
    public:
    void print(){
        cout << "I am student" << endl;
    }
};

class Male{
    public:
    void Maleprint(){
        cout <<"I am male" <<endl;
    }
};

class Female{
    public:
    void Femaleprint(){
        cout <<"I am Female" <<endl;
    }
};

class Boy: public Student, public Male {
    public:
    void Boyprint(){
        cout << "I am Boy" <<endl;
    }
};

class Girl: public Student, public Female {
    public:
    void Girlprint(){
        cout << "I am Girl" <<endl;
    }
};

int main(){
    Girl G1;
    G1.Girlprint();
    G1.print();
    G1.Femaleprint();

    Boy B1;
    B1.Boyprint();
    B1.print();
    B1.Maleprint();
}