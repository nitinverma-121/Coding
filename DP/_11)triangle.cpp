#include <bits/stdc++.h>
using namespace std;

int minimumPathSum(vector<vector<int>>& a, int n){
	
	vector<vector<int>> dp(n, vector<int> (n, 0));
	
	dp[0][0]= a[0][0];
	
	for(int i=1; i< n; i++) dp[i][0]= dp[i-1][0] + a[i][0];
	
	for(int i=1; i< n; i++) {
		for(int j=1; j< a[i].size(); j++) {
			
			int m= a[i].size();
			if(j== m-1) dp[i][j]= a[i][j] + dp[i-1][j-1];
			
			else {
			dp[i][j]= a[i][j] + min(dp[i-1][j-1], dp[i-1][j]);
			}
		}
	}
	
	int ans= INT_MAX;
	
	for(int j= 0; j< a[n-1].size(); j++) {
		ans= min(ans, dp[n-1][j]);
	}
	
	return ans;
}

int main() {

	
	return 0;
}