#include<bits/stdc++.h>
using namespace std;

bool isvalid(int n, int m, int x, int y, vector<vector<bool>>& visited) {
	if(x< 0 or y< 0 or x>= n or y>= m or visited[x][y]== true) {
		return false;
	}
	return true;
}

//analogus to bfs on graph
void bfs(int n, int m, int x, int y) {

	
	vector<vector<bool>> visited(n, vector<bool> (m, false));
	vector<vector<int>> dis(n, vector<int>(m, 0));
	
	int dx[]= {1, -1, 0, 0};
    int dy[]= {0, 0, 1, -1};

	queue<pair<int, int>> q;
	q.push({x, y});
	dis[x][y]= 0;
	visited[x][y]= true;

	while(!q.empty()) {
		int parx= q.front().first;
		int pary= q.front().second;

		q.pop();

		//interate in all possible directions
		for(int i=0; i< 4; i++) {
			   if(isvalid(n, m, parx + dx[i], pary + dy[i], visited) ) {
			   	     int newx= parx + dx[i];
			   	     int newy= pary + dy[i];
			   	     visited[newx][newy]= true;
			   	     q.push({newx, newy});
			   	     dis[newx][newy]= dis[parx][pary] + 1;
			   }
		}
	}

	cout<<endl;

	for(int i=0; i< n; i++) {
		 for(int j=0; j< m; j++) {
		 	cout<<dis[i][j]<<" ";
		 }
		 cout<<endl;
	}

} 


int main() {
	int n, m, x, y;
	cin>>n>>m>>x>>y;
	bfs(n, m, x, y);
	return 0;
}