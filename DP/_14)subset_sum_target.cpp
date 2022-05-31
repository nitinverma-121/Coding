#include<bits/stdc++.h>
using namespace std;

bool help(int n, int k, vector<int> &arr, vector<vector<int>> &dp) {
    
    if(k== 0) return true; 
    
    if(k!= 0 and n==0) return false;
    
    if(dp[n][k]!= -1) {
        return dp[n][k];
    }
    
    if(arr[n-1]<= k) {
        bool op1= help(n-1, k- arr[n-1], arr, dp);
        bool op2= help(n-1, k, arr, dp);
        
        return dp[n][k]= op1 || op2;
    }
  
    else {
        bool op1= help(n-1, k, arr, dp);
        return dp[n][k]= op1;
    }
    
}

bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.    
    vector<vector<int>> dp(n+1, vector<int> (k+1, -1));
    
    return help(n, k, arr, dp);
}

int main() {
    return 0;
}