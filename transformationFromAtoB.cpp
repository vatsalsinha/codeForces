// Online C++ compiler to run C++ program online
#include <iostream>
#include<bits/stdc++.h>
using namespace std;
vector<int> ans;
bool flag = false;
bool solve(long long a, long long b){
    if(a == b && !flag){
        ans.push_back(a);
        flag = true;
        return true;
    }
    if(a > b)
        return false;
    if(solve(2*a, b)){
        ans.push_back(a);
        return true;
    }
    if(solve(10*a+1, b)){
        ans.push_back(a);
        return true;
    }
    return false;
    
}
int main() {
    // Write C++ code here
    long long a, b;
    cin>>a>>b;
    solve(a,b);
    flag == 1 ? cout<<"YES\n" : cout<<"NO\n";
    if(flag){
        cout<<(int)ans.size()<<"\n";
        for(int i = (int)ans.size()-1; i > -1; i--)
            cout<<ans[i]<<" ";
    }

    return 0;
}
