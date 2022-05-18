#include <bits/stdc++.h>
using namespace std;

int help(vector<int> &arr, int i, int n, vector<int> &dp) {

	if(i==0) return 0;
	
	if(dp[i]!= -1) return dp[i];

	int left= help(arr, i-1, n, dp) + abs(arr[i]- arr[i-1]);
	int right= INT_MAX;

	if(i> 1) right= help(arr, i-2, n, dp) + abs(arr[i]- arr[i-2]); 

	return dp[i]= min(left, right);
}


int help_tab(vector<int> &arr, int n) {
	vector<int> dp(n+1, 0);

	dp[0]= 0;
	for(int i=1; i<= n; i++) {
		int l= dp[i-1] + abs(arr[i]- arr[i-1]);
		int r= INT_MAX;
		if(i> 1) r= dp[i-2] + abs(arr[i]- arr[i-2]);

		dp[i]= min(l, r);
	}
	return dp[n-1];
}

//space optimized
int frog_space(vector<int> arr, int n) {

	if(n==0) return 0;

	int a= 0;
	int b= 0;

	for(int i=1; i< n; i++) {
		int l= a + abs(arr[i]- arr[i-1]);
		int r= INT_MAX;
		if(i> 1) r= b + abs(arr[i]- arr[i-2]);

		int c= min(l, r);
		b= a;
		a= c;
	}

	return a;
}



int main() {
	int n;
	cin>>n;
    vector<int> arr(n);
    for(int i=0; i< n; i++) cin>> arr[i];
    
    // int i=n-1;
	// vector<int> dp(n+1, -1);
	// cout<<help(arr, i, n, dp);	

    cout<<frog_space(arr, n);	

	return 0; 
}