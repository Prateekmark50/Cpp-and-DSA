#include<iostream>
using namespace std;

class Area{
public:
    int calculateArea(int r){ // Circle
        return 3.14*r*r;
    }
    int calculateArea(int l, int b){ // Rectangle
        return l*b;
    }
};

int main(){
    Area A1, A2;
    cout << A1.calculateArea(4) << endl;
    cout << A2.calculateArea(4,5) << endl;
}