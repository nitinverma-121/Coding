#include<bits/stdc++.h>
using namespace std;

//Application of Pancake sorting 
//reverse subarray starting from 0th index to make the array equal to the given array

vector<int> help(vector<int> a, vector<int> t, int n) {
	
	vector<int> ans;

	for(int i= n-1; i>= 0; i--) {
		int ele= t[i];

		//search for ele in the left side of the array a
		int idx= i;
		for(int j= i; j>= 0; j--) {
			if(a[j]== ele) {
				idx= j;
				break;
			}
		}
		
		//if it is not at the correct position
		if(idx!= i) {
			ans.push_back(idx+1);
			reverse(a.begin(), a.begin()+ idx+1);
			ans.push_back(i+1);
			reverse(a.begin(), a.begin()+ i+1);
		}
	}	
		return ans;
}


int main() {
	
	int n;
	cin>>n;
	vector<int> a(n, 0);
	for(int i=0; i< n; i++) cin>>a[i]; 

	vector<int> t(n, 0);
	for(int i=0; i< n; i++) cin>>t[i];	

	vector<int> steps= help(a, t, n);
	
	for(int i=0; i< steps.size(); i++) cout<<steps[i]<<" "; 	
		
	return 0;
}