#include <bits/stdc++.h>
using namespace std;

//recursive code
int help(int i, int j) {
	if(i==0 or j==0) return 1;
	
	int a= help(i-1, j);
	int b= help(i, j-1);
	
	return a + b;
}


int uniquePaths(int m, int n) {
	// Write your code here.
	vector<vector<int>> dp(m, vector<int> (n, 0));
	
	for(int i=0; i< m; i++) dp[i][0]= 1;
	for(int j=0; j< n; j++) dp[0][j]= 1;
	
	for(int i=1; i< m; i++) {
		for(int j=1; j< n; j++) {
			dp[i][j]= dp[i-1][j] + dp[i][j-1];
		}
	}
	return dp[m-1][n-1];
	//return help(m-1, n-1);
}

int main() {

	return 0;
}