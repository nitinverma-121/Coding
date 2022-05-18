#include <bits/stdc++.h>
using namespace std;

long long int help(vector<int> arr, int i, int n) {
	
	if(i==0) return arr[0];
	
	if(i< 0) return 0;
	
	long long int inc;
	if(i-2==0) inc= INT_MIN;
	
	else{
		inc= help(arr, i-2, n) + arr[i];
	}
	long long int exc= help(arr, i-1, n);
	
	return max(inc, exc);
}

int main() {
	int n;
	cin>>n;
	
    vector<int> arr(n);
    for(int i=0; i< n; i++) cin>> arr[i];

    	cout<<help(arr, n-1, n);
   
	return 0; 
}









