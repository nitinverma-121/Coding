#include<bits/stdc++.h>
using namespace std;

vector<int> dj{-1, 0, +1};
 
    int help(int i, int j1, int j2, int n, int m, vector<vector<int>> &a, vector<vector<vector<int>>> &dp) {
        
       if(i< 0 or i>= n or j1< 0 or j1>= m or j2< 0 or j2>= m) {
           return 1e-9;
       }
       
       if(i==n-1) {
           if(j1==j2) {
               return a[i][j1];
           }
           else {
               return a[i][j1] + a[i][j2];
           }
       }
      //9 moves possible
        
        if(dp[i][j1][j2]!= -1) return dp[i][j1][j2];
        
        int ans= INT_MIN;
        
        for(int k= 0; k<= 2; k++) {
            for(int h= 0; h<= 2; h++) {
                
                int j1new= j1 + dj[k];
                int j2new= j2 + dj[h];
                
                if(j1==j2) {
                    int val= a[i][j1] + help(i+1, j1new, j2new, n, m, a, dp);
                    ans= max(ans, val);
                }
                else {
                    int val= a[i][j1] + a[i][j2] + help(i+1, j1new, j2new, n, m, a, dp);
                    ans= max(ans, val);
                }
                
            }
        }
        return dp[i][j1][j2]= ans;
    }
    
   
    int cherryPickup(vector<vector<int>>& a) {
        int n= a.size();
        int m= a[0].size();
        
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (m, vector<int> (m, -1)));
        
        
        return help(0, 0, m-1, n, m, a, dp);
    }

    int main() {


        return 0;
    }