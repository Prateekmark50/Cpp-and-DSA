#include<iostream>
using namespace std;

int main(){
    // Array create karna hai, jo store karega address
    int n, m; // n = rows, m = columns
    cout << "Enter the row and column: ";
    cin >> n >> m;
    
    int **ptr = new int *[n];
    // Create 2D Array
    for(int i = 0; i < n; i++){
        ptr[i] = new int [m];
    }

    cout << "Enter the value for array: " << endl;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> ptr[i][j];
        }
    }

    // Print the value
    cout << "The array is: " << endl;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << ptr[i][j] << " ";
        }
        cout << endl;
    }

    // Print the address
    cout << "\n--- Address Information ---" << endl;
    cout << ptr << endl;
    cout << ptr+1 << endl;
    cout << "Address of ptr (i.e., &ptr): " << &ptr << endl;
    for (int i = 0; i < n; i++) {
        cout << "Address of row " << i << " (ptr[" << i << "]): " << ptr[i] << " | Address of &ptr[" << i << "]: " << &ptr[i] << endl;
        for (int j = 0; j < m; j++) {
            cout << "Address of ptr[" << i << "][" << j << "] : " << &ptr[i][j] << endl;
        }
        cout << endl;
    }

    // Release the memory, heap mai
    for(int i = 0; i < n; i++){
        delete[] ptr[i];
    }
    delete[] ptr;
}
// 2 3 4 5
// 4 5 2 1
// 7 3 1 8