#include<iostream>
using namespace std;

int main(){
    int L,B,H;
    cout << "Enter the LENGTH, BREADTH, HEIGHT: ";
    cin >> L >> B >> H; // Dimensions of the 3D array

    int ***ptr = new int **[L];
    // Create 2D array and store it's address in ptr
    for(int i = 0; i < L; i++){
        ptr[i] =  new int *[B];
        // Create 3D array
        for(int j = 0; j < B; j++){
            ptr[i][j] = new int [H];
        }
    }

    // Value is entered in 3D array
    for(int i = 0; i < L; i++){
        for(int j = 0; j <B; j++){
            for(int k = 0; k < H; k++){
                ptr[i][j][k] = i+j+k;
            }
        }
    }

    // Print the value
    for(int i = 0; i < L; i++){
        for(int j = 0; j <B; j++){
            for(int k = 0; k < H; k++){
                cout << ptr[i][j][k] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    // Release the memory, heap mai
    for(int i = 0; i < L; i++){
        for(int j = 0; j < B; j++){
            delete[] ptr[i][j];
        }
        delete[] ptr[i];
    }
    delete[] ptr;
}