#include <bits/stdc++.h>
using namespace std;

void ways(int n, int &count) {
	if(n==0) {
		count++;
		return;
	}

	if(n< 0) return;

	ways(n-1, count);
	ways(n-2, count);
}


int main() {
	int n;
	cin>>n;
    int count= 0;
    ways(n, count);

    cout<<count;

	return 0; 
}