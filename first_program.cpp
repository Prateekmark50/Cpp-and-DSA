// #include<iostream>
// using namespace std;
// int main(){
//     cout<<"hello world";
//     return 0;
// }
// #include<iostream>
// #include<vector>
// #include<algorithm>
// using namespace std;

// string minChar(string str) {
//     // String ko reverse kardo
//     string rev = str;
//     reverse (rev.begin(), rev.end());
//     int size = str.size();
//     string concat = str + '$' + rev;

//     // Longest prefix nikalna hai
//     int n = concat.size();
//     vector<int> lps(n,0);

//     int prefix = 0, suffix = 1;

//     while (suffix < n) {
//         // Matched
//         if (concat[prefix] == concat[suffix]) {
//             lps[suffix] = prefix + 1;
//             prefix ++, suffix ++;
//         }
//         // Not Matched
//         else {
//             if (prefix == 0) {
//                 lps[suffix] = 0;
//                 suffix ++;
//             }
//             else {
//                 prefix = lps[prefix + 1];
//             }
//         }
//     }
//     string str1;
//     for (int i = lps[n - 1]; i < str.size(); i++) {
//         str1 += str[i];
//     }
//     reverse(str1.begin(), str1.end());
//     string result = str1 + str;
//     return result;
// }

// int main() {
//     string str;
//     cout << "Enter the string: ";
//     cin >> str;
    
//     cout << "The no. of character to be added in starting of string: " << minChar(str) << endl;
// }
// #include<iostream>
// using namespace std;
// int main(){
//     int num, rem, ans=0;
//     cout << "enter the number";
//     cin >> num;
//     while(num>0){
//         rem = num % 10;
//         num = num / 10;
//         ans = ans + rem;
//     }
//     if (ans %3 == 0)
//     cout << 1;

//     else
//     cout <<  0;
// }

/*
// Hashdln by deliotte
#include<iostream>
using namespace std;
int main(){
    int n;
    cout<< "Enter the size of array:";
    cin >> n;
    cout<<"Enter the element of array:";
    int heights[n];
    for (int i = 0; i < n; i++) {
        cin >> heights[i];
    }
    // For highest element in array
    int ans1 = 0, ans2 = 0, index1, index2;
    for (int i = 0; i < n; i++) {
        if (ans1 < heights[i]) {
            ans1 = heights[i];
            index1 = i;
        }
    }
    // For second highest element in array (with alteast one gap in b/w and number can be repeatative)
    for (int i = 0; i < n; i++) {
        if (ans2 < heights[i] && index1 != i && i != index1-1 && i != index1+1) {
            ans2 = heights[i];
            index2 = i;
        }
    }
    cout << ans1+ans2;
}
*/
/*
// Hashdln by deliotte
#include<iostream>
#include<vector>
using namespace std;
char firstNonRepeatingCharacter(string S) {
    vector<int> lower(26);
    for(int i = 0; i < S.size(); i++) {
        int pos = S[i] - 'a';
        lower[pos]++;
    }
    for(int i = 0; i < 26; i++) {
        if(lower[i] == 1) {
            char ans = 'a' + i;
            return ans;
        }
    }
    return '_';
}
int main(){
    string S;
    cout << "Enter the string: ";
    cin >> S;
    cout << firstNonRepeatingCharacter(S);
}
*/
#include<iostream>
using namespace std;
void Sum(int m, int n){
    int ans = m+n;
    cout << ans << endl;
}
int Multiply(int m, int n){
    int ans = m*n;
    return ans;
}
int main(){
    int a, b;
    cout << "Enter the number: ";
    cin >> a >> b;
    // Sum(a,b);
    cout << Multiply(a,b);
}