#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    // create 2D vector
    vector<vector<int> >matrix(3,vector<int>(4,1));

    for(int i=0; i<3; i++){
        for(int j=0; j<4; j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }

    // If i want to no. of rows and columns
    cout<<"Rows = "<<matrix.size()<<endl;
    cout<<"Columns = "<<matrix[0].size()<<endl;

    // Create 2D vector taking input from user
    int n,m;
    cout<<"Enter the size of row and column: ";
    cin>>n>>m;
    vector<vector<int> >newvector(n,vector<int>(m,1));

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>newvector[i][j];
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout<<newvector[i][j]<<" ";
        }
        cout<<endl;
    }
}