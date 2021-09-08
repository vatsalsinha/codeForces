// Online C++ compiler to run C++ program online
#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int main() {
    // Write C++ code here
    vector<int> arr = {2,5,7,9,8,7,4};
    int k = 5;
    int countLegalElements = 0;
    for(int i = 0; i < arr.size(); i++){
        if(arr[i] <= k)
            countLegalElements++;
    }
    int maxCount = INT_MIN, count = 0;
    for(int i = 0; i < countLegalElements; i++){
        if(arr[i] <= k)
            count++;
    }
    //cout<<count;
    for(int i = countLegalElements; i < arr.size(); i++){
        maxCount = max(maxCount, count);
        if(arr[i] <= k)
            count++;
        else if(arr[i-k] <= k)
            count--;
    }
    cout<<countLegalElements - maxCount;
    return 0;
}
