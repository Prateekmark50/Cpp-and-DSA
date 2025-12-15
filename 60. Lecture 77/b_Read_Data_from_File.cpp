#include<iostream>
#include<fstream>
using namespace std;

int main(){
    // File ko open karo
    ifstream fin;
    fin.open("zoom.txt"); // If file is present the it will open it. And if file is not present it will create the file and then open that file
    // Fir read karo
    char c;
    c = fin.get();
    while(!fin.eof()){ // eof is end of file
        cout << c;
        c = fin.get();
    }
    fin.close(); // Resource release kar pau
}