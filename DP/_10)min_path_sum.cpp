#include <bits/stdc++.h>
using namespace std;

int minSumPath(vector<vector<int>> &a) {
    // Write your code here.
	int n= a.size();
	int m= a[0].size();
	
	vector<vector<int>> dp(n, vector<int> (m, 0));
	
	dp[0][0]= a[0][0];
	
	for(int i=1; i< n; i++) {
		dp[i][0]= dp[i-1][0] + a[i][0];
	}
	
	
	for(int j=1; j< m; j++) {
		dp[0][j]= dp[0][j-1] + a[0][j];
	}
	
	
	
	for(int i=1; i< n; i++) {
		for(int j=1; j< m; j++) {
			dp[i][j]= min(dp[i-1][j], dp[i][j-1]) + a[i][j];
		}
	}
	return dp[n-1][m-1];
}

int main() {

	return 0;
}