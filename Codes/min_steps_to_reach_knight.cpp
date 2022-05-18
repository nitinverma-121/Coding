#include<bits/stdc++.h>
using namespace std;

vector<int> dx{2, 2, 1, 1, -1, -2, -2, -1};
    vector<int> dy{-1, 1, 2, -2, -2, -1, 1, 2};
    
    
    bool isvalid(int x, int y, int N, vector<vector<bool>> &visited) {
         if(x< 0 or y< 0 or x>= N or y>= N or visited[x][y]== true) {
              return false;
         }
         return true;
    }
    
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    // Code here
	    
	    int sx, sy, ex, ey;
	    //since they were in 1 based indexing
	    sx= KnightPos[0]-1;
	    sy= KnightPos[1]-1;
	    ex= TargetPos[0]-1;
	    ey= TargetPos[1]-1;
	   
	    queue<pair<int, int>> q;
	    q.push({sx, sy});
	    
	    vector<vector<int>> dis(N, vector<int>(N, 0));
	    vector<vector<bool>> visited(N, vector<bool> (N, false));
	    
	    dis[sx][sy]= 0;
	    visited[sx][sy]= true;
	    
	    
	    while(!q.empty()) {
	        int parx= q.front().first;
	        int pary= q.front().second;
	        
	        q.pop();
	        
	        for(int i=0; i< 8; i++) {
	            if(isvalid(parx + dx[i], pary + dy[i], N, visited)) {
	                int newx= parx + dx[i];
	                int newy= pary + dy[i];
	                dis[newx][newy]= dis[parx][pary] + 1;
	                visited[newx][newy]= true;
	                q.push({newx, newy});
	            }
	        }
	    }
	    return dis[ex][ey];
	}


int main() {
	int n, m, x, y;
	cin>>n>>m>>x>>y;
	bfs(n, m, x, y);
	return 0;
}