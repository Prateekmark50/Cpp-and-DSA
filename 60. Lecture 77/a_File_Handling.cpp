/*
#include<iostream>
#include<fstream>
using namespace std;

int main(){
    // File jo open karna
    ofstream fout;
    fout.open("zoom.txt"); // If file is present the it will open it. And if file is not present it will create the file and then open that file
    // Write kar sakta hu
    fout << "Hello India";
    fout.close(); // Resource release kar pau
}
*/
#include<iostream>
#include<fstream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    vector<int> arr(5);
    cout << "Enter the input: ";
    for(int i = 0; i < 5; i++){
        cin >> arr[i];
    }

    // File ko open karo
    ofstream fout;
    fout.open("zero.txt");
    fout << "Original Data\n";
    for(int i = 0; i < 5; i++){
        fout <<arr[i] << " ";
    }
    fout << "\nSorted Data\n";
    sort(arr.begin(), arr.end());
    for(int i = 0; i < 5; i++){
        fout <<arr[i] << " ";
    }
    fout.close();
}