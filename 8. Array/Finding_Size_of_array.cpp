#include<iostream>
using namespace std;

int main()
{
    // there is way we can find the size of array means how much space it take
    int arr[5]={1,2,3,4,5};
    cout<<sizeof(arr)<<endl;//--> yaha par answer 20 show karega because array ko hamne integer value de rakhi hai
    // for finding how many elements are there in an array
    cout<<sizeof(arr)/sizeof(arr[0])<<endl;

    // To find how much byte integer take in memory
    int a;
    cout<<sizeof(a)<<endl;

    // To find how much byte char take in memory
    char b;
    cout<<sizeof(b)<<endl;

    // To find how much byte float take in memory
    float c;
    cout<<sizeof(c)<<endl;

    // To find how much byte boolean take in memory
    bool d;
    cout<<sizeof(d)<<endl;
}