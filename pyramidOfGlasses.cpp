#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, t;
    cin>>n>>t;
    vector<vector<double>> vec(n, vector<double>(n,0));
    while(t--){
        vec[0][0] += 1;
        for(int i = 0; i < n-1; i++){
            for(int j = 0; j < i+1; j++){
                if(vec[i][j] <= 1)
                    continue;
                double k = (vec[i][j] - 1) / 2.0;
                vec[i+1][j] += k;
                vec[i+1][j+1] += k;
                vec[i][j] = 1; // itna hi store kar saktaa hai
            }
        }
    }
    int cnt = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < i+1; j++){
                if(vec[i][j] >= 1)
                    cnt++;
            }
        }
    cout<<cnt;
    return 0;
}
