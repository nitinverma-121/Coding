#include <bits/stdc++.h>
using namespace std;

int mazeObstacles(int n, int m, vector< vector< int> > &mat) {
    // Write your code here
	
	if(mat[0][0]==-1 or mat[n-1][m-1]== -1) return 0; 
	
	vector<vector<long long int>> dp(n, vector<long long int> (m, 0));
	long long int M= 1000000007;
	for(int i=0; i< n; i++) {
		if(mat[i][0]==-1) break;
		dp[i][0]= 1;
	}
	
	for(int j=0; j< m; j++) {
		if(mat[0][j]==-1) break;
		dp[0][j]= 1;
	}
	
	for(int i=1; i< n; i++) {
		for(int j= 1; j< m; j++) {
			if(mat[i][j]!= -1) {
				dp[i][j]= (dp[i-1][j] % M + dp[i][j-1] % M) % M;
			}
		}
	}
	
	
	return dp[n-1][m-1] % M;
}

int main() {

	return 0;
}