#include<bits/stdc++.h>
using namespace std;
 
int main(){
    int n, m;
    cin>>n;
    cin>>m;
    int mood[n+1];
    for(int i = 1; i < n+1; i++)
        cin>>mood[i];
    int preSum[n+1];
    preSum[0] = 0;
    for(int i = 1; i < n+1; i++){
        preSum[i] = preSum[i-1] + mood[i];
    }
    int ans = 0;
    for(int i = 0; i < m; i++){
        int l, r;
        cin>>l>>r;
        int sum = preSum[r] - preSum[l-1];
        if(sum > 0)
            ans += sum;
    }
    cout<<ans;
    return 0;
}
