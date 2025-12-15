#include<iostream>
using namespace std;

int countVowels(string str, int index){
    // Base Case
    if(index == -1){
        return 0;
    }
    // Vowels hoga
    if(str[index]=='a'||str[index]=='e'||str[index]=='i'||str[index]=='o'||str[index]=='u'){
        return 1 + countVowels(str, index-1);
    }
    // Nahi hoga
    else{
        return countVowels(str, index-1);
    }
}

int main(){
    // count vowels
    string str = "rohit";
    cout << countVowels(str,4);
}