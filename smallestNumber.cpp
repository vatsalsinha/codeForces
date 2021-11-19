// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;
vector<long long> nums(4);
vector<char> ops(3);
long long ans = LLONG_MAX;
void fnd(int index){
    if(index > 2)
        return;
    for(int i = 0; i < 4; i++){
        for(int j = i+1; j < 4; j++){
            if(nums[i] != -1 && nums[j] != -1){// if not visited;
                long long a1 = nums[i], a2 = nums[j];
                nums[i] = -1; // mark as visited
                if(ops[index] == '*'){
                    nums[j] = a1*a2;
                }
                if(ops[index] == '+'){
                    nums[j] = a1+a2;
                }
                if(index == 2){
                    if(nums[j] < ans){
                        ans = nums[j];
                    }
                }
                fnd(index+1);
                nums[i] = a1, nums[j] = a2;
            }
        }
    }
        
    
}
int main() {
    // Write C++ code here
    for(int i = 0; i < 4; i++)
        cin>>nums[i];
    for(int i = 0; i < 3; i++)
        cin>>ops[i];
    fnd(0);
    cout<<ans;
    return 0;
}
