#include<bits/stdc++.h>
using namespace std;
int getMaxPathSum(vector<vector<int>> &a)
{
	int n= a.size();
	int m= a[0].size();
	
	vector<vector<int>> dp(n, vector<int> (m, 0));
	
	for(int j=0; j< m; j++) dp[0][j]= a[0][j];
	
	for(int i=1; i< n; i++) {
		for(int j=0; j< m; j++) {
			if(j==0) {
				dp[i][j]= a[i][j] + max(dp[i-1][j], dp[i-1][j+1]);
			} 
			else if(j==m-1) {
				dp[i][j]= a[i][j] + max(dp[i-1][j], dp[i-1][j-1]);
			}
			else {
				dp[i][j]= a[i][j] + max({dp[i-1][j-1], dp[i-1][j], dp[i-1][j+1]});
			}
		}
	}
	
	int ans= INT_MIN;
	for(int j=0; j< m; j++) ans= max(ans, dp[n-1][j]);
	
	return ans;
    //  Write your code here.
}

int main() {

	return 0;
}