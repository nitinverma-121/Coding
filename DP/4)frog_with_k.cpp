#include <bits/stdc++.h>
using namespace std;


//f(x)=> 0 to x thak ki min cost kya hai
unordered_map<string, int> um;

int frog(vector<int> &arr, int i, int n, int k, vector<int> &dp) {

	if(dp[i]!= -1) return dp[i];

	if(i==0) return dp[i]= 0;

	int ans= INT_MAX;

	for(int step= 1; step<= k; step++) {
		//check if i can take the step
		if(i>= step) {

		     int a= frog(arr, i- step, n, k, dp) + abs(arr[i]- arr[i-step]); 
		     ans= min(ans, a);

		}
	}
	
	return dp[i]= ans;
}



int main() {
	int n;
	cin>>n;
	int k;
	cin>>k;

    vector<int> arr(n);
    for(int i=0; i< n; i++) cin>> arr[i];
    

    vector<int> dp(n+1, -1);

    cout<<frog(arr, n-1, n, k, dp);	

	return 0; 
}