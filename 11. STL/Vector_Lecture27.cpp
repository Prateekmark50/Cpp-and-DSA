#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    // // create vector , declare
    // vector<int>v;
    // vector<int>v1(5,1);
    // // size and capacity
    // cout<<"Size of v: "<<v.size()<<endl;
    // cout<<"Capacity of v: "<<v.capacity()<<endl;
    // v.push_back(2);
    // v.push_back(3);
    // v.push_back(10);
    // cout<<"Size of v: "<<v.size()<<endl;
    // cout<<"Capacity of v: "<<v.capacity()<<endl;
    // // Update the value
    // v[1]=5;
    // cout<<"Size of v1: "<<v1.size()<<endl;
    // cout<<"Capacity of v1: "<<v1.capacity()<<endl;
    // v1.push_back(8);
    // cout<<"Size of v1: "<<v1.size()<<endl;
    // cout<<"Capacity of v1: "<<v1.capacity()<<endl;

    // vector<int>v3 = {1,2,3,4,5};
    // cout<<"Size of v3: "<<v3.size()<<endl;
    // cout<<"Capacity of v3: "<<v3.capacity()<<endl;
    // v3.push_back(8);
    // cout<<"Size of v3: "<<v3.size()<<endl;
    // cout<<"Capacity of v3: "<<v3.capacity()<<endl;

    // // Delete value from vector
    // vector<int>vnew;
    // vnew.push_back(4);
    // vnew.push_back(41);
    // vnew.push_back(14);
    // vnew.push_back(42);
    // vnew.push_back(84);
    // vnew.pop_back();
    // cout<<"Size of vnew: "<<vnew.size()<<endl;
    // cout<<"Capacity of vnew: "<<vnew.capacity()<<endl;

    // vnew.erase(vnew.begin()+1);
    // cout<<"Size of vnew: "<<vnew.size()<<endl;
    // cout<<"Capacity of vnew: "<<vnew.capacity()<<endl;
    // for(int i=0;i<vnew.size();i++)
    // cout<<vnew[i]<<" ";
    // vnew.insert(vnew.begin()+1,50);//insert value
    // cout<<endl;
    // for(int i=0;i<vnew.size();i++)
    // cout<<vnew[i]<<" ";

    // vnew[1]=37;
    // cout<<endl;
    // for(int i=0;i<vnew.size();i++)
    // cout<<vnew[i]<<" ";

    // vnew.clear();//Remove all the element
    // cout<<endl;
    // cout<<"Size of vnew: "<<vnew.size()<<endl;
    // cout<<"Capacity of vnew: "<<vnew.capacity()<<endl;

    // vector<int>arr;
    // arr.push_back(2);
    // arr.push_back(12);
    // arr.push_back(21);
    // arr.push_back(122);
    // cout<<arr[0]<<endl;
    // cout<<arr.front()<<endl;
    // cout<<arr[arr.size()-1]<<endl;
    // cout<<arr.back()<<endl;

    // vector<int>a;
    // // Copy value of 1 vector to another
    // a = arr;
    // cout<<a.size()<<endl;
    // for(auto it = arr.begin();it!=arr.end();it++){
    //     cout<<*it<<" ";
    // }
    // cout<<endl;
    // for(auto i: arr)
    // cout<<i<<" ";

    vector<int>ans;
    ans.push_back(5);
    ans.push_back(235);
    ans.push_back(15);
    ans.push_back(54);
    ans.push_back(125);
    // Sort in increasing order
    sort(ans.begin(),ans.end());//I have used #include<algorith> library to run this sort function
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    // // sort in decreasing order
    // sort(ans.begin(),ans.end(), greater<int>());
    // for(int i=0;i<ans.size();i++){
    //     cout<<ans[i]<<" ";
    // }
    // cout<<endl;
    // // Another way we sort in decreasing order
    // sort(ans.rbegin(),ans.rend());
    // for(int i=0;i<ans.size();i++){
    //     cout<<ans[i]<<" ";
    // }
    // cout<<endl;
    cout<<binary_search(ans.begin(),ans.end(),55)<<endl;//it return answer in 1 or 0
    cout<<binary_search(ans.begin(),ans.end(),54)<<endl;//it return answer in 1 or 0
    cout<<find(ans.begin(),ans.end(),54)-ans.begin()<<endl;

    //Count
    vector<int>v4;
    v4.push_back(3);
    v4.push_back(2);
    v4.push_back(1);
    v4.push_back(3);
    v4.push_back(3);
    v4.push_back(5);
    v4.push_back(3);
    sort(v4.begin(),v4.end());
    for(int i=0;i<v4.size();i++){
        cout<<v4[i]<<" ";
    }
    cout<<endl;
    cout<<"Number of times 3 appear: "<<count(v4.begin(),v4.end(),3)<<endl;
    cout<<"The maximum element in vector v4 is: "<<*max_element(v4.begin(),v4.end())<<endl;
    cout<<"The minimum element in vector v4 is: "<<*min_element(v4.begin(),v4.end())<<endl;

    //lower bound
    cout<<lower_bound(v4.begin(),v4.end(),4)-v4.begin()<<endl;
}