#include<bits/stdc++.h>

vector<vector<int>> help(vector<int> &arr, int &n, int sum) {
    
    vector<vector<int>> dp(n+1, vector<int> (sum+1, 0));
    
    for(int i=0; i< n+1; i++) dp[i][0]= 1;
    
    for(int i=1; i< n+1; i++) {
        for(int j=1; j< sum+1; j++) {
            if(arr[i-1]<= j) {
                 dp[i][j]= dp[i-1][j] || dp[i-1][j- arr[i-1]];
            }
            else {
                dp[i][j]= dp[i-1][j];
            }
        }
    }
    return dp;
}

int minSubsetSumDifference(vector<int>& arr, int n)
{
	int sum= 0;
    for(int i=0; i< n; i++) sum+= arr[i];
    
    int ans= INT_MAX;
    
    vector<vector<int>> dp= help(arr, n, sum);
    
    for(int i=0; i<= sum/2; i++) {
        
        if(dp[n][i]) {
             ans= min(ans, abs(sum- 2* i));
        }
    }
    
    return ans;
}
