#include<bits/stdc++.h>
/*
So as bharat sir,  said find the prefix sum for brightness
Since for coordinates 1,1 and 2,2 there is only one star present.
 With initial brightness 1
So at time t = 2 brightness becomes 1+1+1 = 3
 In the q array,  first column is the time for which we have to calculate the brightness
So like we used to calculate the sum of submatrix, we will calculate the brightness if we have the prefix sum for the matrix
 See every second the brightness increases by 1
 And in the stars array ,the third column denotes initial brightnezs
 As soon as the brightness becomes greater than maximum brightness,  it becomes zero and starts increasing again by 1 every second 
*/
using namespace std;
int arr[11][101][101];
int main(){
    int n, q, c, a, b, s, t, x1, y1, x2, y2;
    cin>>n>>q>>c;
    for(int i = 0; i < n; i++){
        cin>>a>>b>>s;
        for(int i = 0; i < c+1; i++)
            arr[i][a][b] += (s+i)%(c+1);
    }
    for(int i = 0; i < c+1; i++){
        for(int j = 1; j < 101; j++){
            for(int k = 1; k < 101; k++){
                arr[i][j][k] += arr[i][j-1][k] + arr[i][j][k-1] - arr[i][j-1][k-1];
            }
        }
    }
    for(int i = 0; i < q; i++){
        cin>>t>>x1>>y1>>x2>>y2;
        t %= (c+1);
        cout<<arr[t][x1-1][y1-1] + arr[t][x2][y2] - arr[t][x2][y1-1] - arr[t][x1-1][y2]<<"\n";
    }
    return 0;
}
