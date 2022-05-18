#include <bits/stdc++.h>
using namespace std;

//using tabulation
//O(N) time
//O(N) space
int fib_tab(int n) {

	vector<int> dp(n+1, 0);

	dp[0]= 0;
	dp[1]= 1;



	for(int i= 2; i< n+1; i++) {
		dp[i]= dp[i-1]+ dp[i-2];
	}


	return dp[n]; 
}

//space optimized dp
int fib_space(int n) {

	if(n==0) return 0;
	if(n==1) return 1;
	//a, b, c
	int a= 0;
	int b= 1;
	for(int i= 2; i< n+1; i++) {
		int c= a + b;
		a= b;
		b= c;
	}
	return b;
}


//using memoization
//O(N) time
//O(N) space
int fib(int n, vector<int> &dp) {

	if(n==0) return dp[n]= 0;
	if(n==1) return dp[n]= 1;
	
	if(dp[n]!= -1) return dp[n];

	return dp[n]= fib(n-1, dp) + fib(n-2, dp);
}


int main() {
	int n;
	cin>>n;
    
    vector<int> dp(n+1, -1);

	cout<<fib(n-1, dp);

	//cout<<fib_tab(n-1);

	return 0;
}
