#include<bits/stdc++.h>
using namespace std;
long long int calculateMaximum(vector<long long int>& nums, int p, int q, int r){
    int n = (int)nums.size();
    long long int pMax[n], sMax[n];
    pMax[0] = p*nums[0];
    sMax[n-1] = r*nums[n-1];
    for(int i = 1; i < n; i++)
        pMax[i] = max(pMax[i-1], nums[i]*p);
    for(int i = n-2; i > -1; i--)
        sMax[i] = max(sMax[i+1], nums[i]*r);
    long long int ans = LLONG_MIN;
    for(int i = 0; i < n; i++){
        long long int sum = pMax[i] + q*nums[i] + sMax[i];
        ans = max(sum, ans);
    }
    return ans;
}
int main(){
    long long int n,p,q,r;
    cin>>n;
    cin>>p;
    cin>>q;
    cin>>r;
    vector<long long int> nums(n);
    for(int i = 0; i < n; i++){
        cin>>nums[i];
    }
    cout<<calculateMaximum(nums, p, q, r);
    return 0;
}
