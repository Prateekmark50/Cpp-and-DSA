// //Leetcode
// Method 1
// #include<iostream>
// #include<vector>
// using namespace std;

// int winner(vector<bool> person, int n, int index, int person_left, int k){
//     if(person_left == 1){
//         for(int i = 0; i < n; i++){
//             if(person[i] == 0){
//                 return i+1;
//             }
//         }
//     }
//     int kill = (k-1) % person_left;
//     while(kill--){
//         index = (index+1) % n;
//         while(person[index] == 1){
//             index = (index+1) % n;
//         }
//     }
//     person[index] = 1;
//     while(person[index] == 1){
//         index = (index+1) % n;
//     }
//     return winner(person, n, index, person_left-1, k);
// }

// int main(){
//     int n = 5;
//     int k = 2;
//     vector<bool> person(n,0);
//     cout << winner(person, n, 0, n, k);
// }
// /*
// Time Complexity:-
//     O(n^2)
// Space Complexity:-
//     O(n)
// */

// Optimized Code Method 2
#include<iostream>
#include<vector>
using namespace std;

int winner(int n, int k){
    if(n == 1){
        return 0;
    }
    return (winner(n-1,k)+k)%n;
}

int main(){
    int n = 5;
    int k = 2;
    vector<bool> person(n,0);
    cout << winner(n,k)+1;
}
/*
Time Complexity:-
    O(n)
Space Complexity:-
    O(n)
*/