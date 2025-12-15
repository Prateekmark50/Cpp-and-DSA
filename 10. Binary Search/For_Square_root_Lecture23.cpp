#include<iostream>
using namespace std;

int mySqrt(int x){
    if(x<2)
    return x;
    int start=0, end=x, mid, ans;
    while(start<=end){
        mid = start+(end-start)/2;
        if(mid == x/mid){//--> means if(mid*mid = x)
            ans=mid;
            break;
        }
        else if(mid < x/mid){//--> means else if(mid*mid < x)
            ans=mid;
            start = mid+1;
        }
        else
        end = mid-1;
    }
    return ans;
}

int main(){
    int x;
    cout<<"Enter the number: ";
    cin>>x;
    cout<<"The square root of "<< x <<" is "<<mySqrt(x);
}