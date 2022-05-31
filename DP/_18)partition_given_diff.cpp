
#include<bits/stdc++.h>

int help(vector<int> &arr, int n, int sum) {  
    
    long long int M=  1e9 + 7;
    
    vector<vector<long long>> dp(n+1, vector<long long> (sum+1, 0));
    
    for(int i=0; i< n+1; i++) dp[i][0]= 1;
    
    for(int i=1; i< n+1; i++) {
        for(int j=0; j< sum+1; j++) {
            if(arr[i-1]<= j) {
                dp[i][j]= (dp[i-1][j] % M + dp[i-1][j- arr[i-1]] %M) % M;
            }
            else {
                dp[i][j]=  dp[i-1][j] % M;
            }
        }
    }
    
    return dp[n][sum] % M;
}

int countPartitions(int n, int d, vector<int> &arr) {
    // Write your code here.
    
    int sum= 0;
    
    for(int i=0; i< n; i++) {
        sum+= arr[i];
    }
    
    if((d + sum)% 2!= 0) return 0;
    
    if(d> sum) return 0;
    
    
    int g =(d + sum)/2;
 
    int count= 0;
    
    return help(arr, n, g) ;
}


