
int help(vector<int> &arr, int i, int n, vector<int> &dp) {
	
	if(dp[i]!= -1) return dp[i];
	
	if(i==0) return dp[i]= arr[0];
	if(i< 0) return dp[i]= 0;
	
	int inc= help(arr, i-2, n, dp) + arr[i] ;
	int exc= help(arr, i-1, n, dp);
	
	return dp[i]= max(inc, exc);
}

int topd(vector<int> arr, int n) {
	
	vector<int> dp(n+1, 0);
	dp[0]= arr[0];
	
	for(int i=1; i< n; i++) {
		int inc= dp[i-2] + arr[i];
		int exc= dp[i-1];
		dp[i]= max(inc, exc);
	}
	return dp[n-1];
}

int space(vector<int> arr, int n) {
	
	if(n==1) return arr[0];
	
	int a= 0;
    int b= 0;
	
	for(int i=0; i< n; i++) {
		int inc= a + arr[i];
		int exc= b;
		int c= max(inc, exc);
		a= b;
		b= c;
	}
	return b;
}
int main() {
	int n;
	cin>>n;
	
    vector<int> arr(n);
    for(int i=0; i< n; i++) cin>> arr[i];
   
	return 0; 
}









