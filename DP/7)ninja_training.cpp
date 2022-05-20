#include <bits/stdc++.h>
using namespace std;

int ninjaTraining(int n, vector<vector<int>> &a)
{
    // Write your code here.
	int m= a[0].size();
	
	vector<vector<int>> dp(n, vector<int>(m, 0));
	
	//first row initialized
	for(int j=0; j< m; j++) dp[0][j]= a[0][j];
	
	for(int i=1; i< n; i++) {
		
		//pichli row ka max and second max nikal le
		//to avoid max and second max clash store indexed too
		int maxele= INT_MIN;
		int idx= -1;
		int secondmax= INT_MIN;
		
		for(int j=0; j< m; j++) {
			if(dp[i-1][j]> maxele) {
				maxele= dp[i-1][j];
				idx= j;
			}
		}
		
		for(int j=0; j< m; j++) {
			if(dp[i-1][j]> secondmax and j!= idx) {
				secondmax= dp[i-1][j];
			}
		}
		
		for(int j=0; j< m; j++) {
			if(dp[i-1][j]!= maxele) {
				dp[i][j]= a[i][j] + maxele;
			}
			else{
				dp[i][j]= a[i][j] + secondmax;
			}
		}
		
	}
	
	//ans will be the max of the last dp row
	
	int ans= INT_MIN;
	for(int j=0; j< m; j++) {
		ans= max(ans, dp[n-1][j]);
	}
	
	return ans;
}

int main() {
	int n, m;
	cin>>n>>m;

	vector<vector<int>> arr(n, vector<int> (m, 0));
	for(int i=0; i< n; i++) {
		for(int j=0; j< m; j++) {
			 cout<<i<<" "<<j<<"||";
		}
		cout<<endl;
	}
    
	return 0; 
}









