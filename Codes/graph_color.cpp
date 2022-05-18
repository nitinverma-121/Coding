#include<bits/stdc++.h>
using namespace std;


//can i color the cth ball using ith color
//you can if the neighbour of c is not painted
//with the ith color
bool valid(vector<int> g[], vector<int> color, int c, int i) {
	 for(auto child: g[c]) {
	 	  if(color[child]== i) return false;
	 }
	 return true;
}

//M color selection problem
//can we color graph using m colors or not
bool cancolor(vector<int> g[], vector<int> &color, int n, int m, int c) {
	
	//i have colored all balls/nodes
	if(c== n) {
		return true;
	}

	//i have to choose a color for a ball/node
	//inorder to color the cth ball/node
	//i will chose the color among all possible options
	for(int i= 1; i<= m; i++) {
		//i hve to check can i color the cth ball using ith color
		if(valid(g, color, c, i)) {
			 color[c]= i;
			 bool f= cancolor(g, color, n, m, c+1);
			 if(f== true) return true;
			 color[c]= 0; //back tracking
		}
	}
	return false;
}

//M color permutation problem 
//number of ways and exact order in which graph can be
//colored using M colors

void permute_color(vector<int> g[], vector<int> &color, int n, int m, int c) {

	//i am done with the graph
	if(c== n) {
		//print the color orientation
		for(int i=0; i< color.size(); i++) {
			cout<<color[i]<<" ";
		}
		cout<<endl;
		return;
	}
	//paint the cth ball/node using the possible color set 

	for(int i=1; i<= m; i++) {
		if(valid(g, color, c, i)) {
			 color[c]= i;
			 permute_color(g, color, n, m, c+1);
			 color[c]= 0; //back tracking
		}
	}
}

//M color optimisation problem
//minimum number of colors req. to 
//paint a graph so that no 2 adj. have same color(chromatic number) 
//it is NP- Complete


int main() {
    
    //n => Number of vertices
    //e => Number of edges

    int n, e;
    cin>>n>>e;

    vector<int> g[n];
    for(int i=0; i< e; i++) {
    	int x, y;
    	cin>>x>>y;
    	g[x].push_back(y);
    	g[y].push_back(x);
    }
    vector<int> color(n, 0);
    // cout<<cancolor(g, color, n, 3, 0);
    // cout<<endl;
    permute_color(g, color, n, 2, 0);
    return 0;
}
