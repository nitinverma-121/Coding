#include<bits/stdc++.h>
using namespace std;

bool canPartition(vector<int> &arr, int n)
{
	// Write your code here.
    int sum= 0;
    for(int i=0; i< n; i++) sum+= arr[i];
    
    if(sum% 2!= 0) return false;
    
    sum= sum/2;
    
    //check if arr has a subset that has a sum (Sum)
    
    vector<vector<int>> dp(n+1, vector<int> (sum+1, 0));
    
    for(int i=0; i< n+1; i++) dp[i][0]= 1;
    
    for(int i=1; i< n+1; i++) {
        for(int j=1; j< sum+1; j++) {
             if(arr[i]<= j) {
                 bool op1= dp[i-1][j- arr[i]];
                 bool op2= dp[i-1][j];
                 
                 dp[i][j]= op1 || op2;
             }
            else {
                bool op1= dp[i-1][j];
                dp[i][j]= op1;
            }
        }
    }
    return dp[n][sum];
}

int main() {

    return 0;
}