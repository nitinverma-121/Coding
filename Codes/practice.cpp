#include<bits/stdc++.h>
using namespace std;


void help(string ip, string op, int &count) {

   if(ip.size()==0) {
   	  cout<<op<<endl;
   	  count++;
   	  return;
   }

   char a= ip[0];
   ip.erase(ip.begin());

   string op1(op);
   string op2(op);

   op1.push_back(a);

   help(ip, op1, count);
   help(ip, op2, count);
}



int main() {
	
	string ip;
	cin>>ip;

	string op;
	int count= 0;
	help(ip, op, count);
	cout<<count;

}