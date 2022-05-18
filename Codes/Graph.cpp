#include<bits/stdc++.h>
using namespace std;


void DFS(vector<int> arr[], int n, int r) {

    vector<bool> visited(n, false);
    visited[r]= true;
    stack<int> s;
    s.push(r);

    while(!s.empty()) {

    	int t= s.top();
    	s.pop();
    	cout<<t<<" ";

    	for(auto child: arr[t]) {
    		 if(visited[child]== false) {
    		 	   visited[child]= true;
    		 	   s.push(child);
    		 }
    	}

    }
}

void DFS_RECUR(vector<int> arr[], int n, int r, vector<bool> &visited) {

	cout<<r<<" ";
	visited[r]= true;

	for(auto child: arr[r]) {
		  if(visited[child]== false) {
		  DFS_RECUR(arr, n, child, visited);
		}
	}
}

//BFS
bool iscycle(vector<int> arr[], int n, int r) {
	vector<bool> visited(n+1, false);
	queue<int> q;
	visited[r]= true;
	q.push(r);

	vector<int> parent(n+1, 0);

	while(!q.empty()) {
		int t= q.front();
		q.pop();
		for(auto child: arr[t]) {
			  if(visited[child]==false) {
			  	  visited[child]= true;
			  	  parent[child]= t;
			  	  q.push(child);
			  }
			  else{
			  	//i have to check
			  	//ki jo visit ho gya hai
			  	//kahi vo parent to nhi hai
			  	if(parent[t]!= child) return true;
			  }
		}
	}
	return false;
}

//only works for undirected graphs
bool iscycle_dfs(vector<int> arr[], vector<int> &parent, vector<bool> &visited, int n, int r) {

	visited[r]= true;

	for(auto child: arr[r]) {
		  if(visited[child]== false) {
		  	 parent[child]= r;
		  	 bool temp= iscycle_dfs(arr, parent, visited, n, child);
		  	 if(temp) return true;
		  }
		  else {
		  	if(parent[r]!= child) {
		  		 return true;
		  	}
		  }
	}
	return false;
}



//CHECK FOR BIPARTITE THROUGH DFS
bool help(vector<int> g[], int s, vector<bool> &visited, vector<int> &color) {
        
        visited[s]= true;
        if(color[s]== -1) color[s]= 0;
        
        for(auto child: g[s]) {
            if(visited[child]== false) {
                 //if it is not visited
                 //it will not be colored too
                 color[child]= 1- color[s];
                 bool d= help(g, child, visited, color);
                 if(!d) return false;
            }
            else {
                //if it is visited
                //vo colored bhi hogii
                if(color[s]== color[child]) return false;
            }
        }
        return true;
    } 
    
  bool isBipartite(int V, vector<int>adj[]){
      
      // Code here
      vector<bool> visited(V, false);
      vector<int> color(V, -1);
      
      for(int i=0; i< V; i++) {
           if(visited[i]== false) {
               bool a= help(adj, i, visited, color);
               if(!a) return false;
           }
      }
      return true;
  }

  //CHECK FOR BIPARTITE BFS
bool bipar_BFS(vector<int> arr[], int s, vector<bool> &visited, vector<int> &color) {
    queue<int> q;
    visited[s]= true;
    color[s]= 0;
    q.push(s);

    while(!q.empty()) {
       
       int p= q.front();
       q.pop();
       for(auto t: arr[p]) {
          
           if(visited[t]== false) {
               color[t]= 1- color[p];
               visited[t]= true;
               q.push(t);
           }
           else {
            if(color[t]== color[p]) return false;
           }
       }
    }
    return true;
  }

  //shortest distance from a given node to all nodes
  //with unit weight

  vector<int> shortest_dis(vector<int> arr[], int n) {
    vector<int> dis(n, -1);
    queue<int> q;
    vector<bool> visited(n, false);

    q.push(0);
    visited[0]= true;
    dis[0]= 0;

    while(!q.empty()) {
      int p= q.front();
      q.pop();

      for(auto child: arr[p]) {
           if(visited[child]== false) {
                visited[child]= true;
                dis[child]= dis[p] + 1;
                q.push(child);
           }
      }
    }
    return dis;
  }  
  
  //undirected weighted graph
  vector<int> dijstra(vector<pair<int, int>> arr[], int n, int s) {
    vector<int> dis(n+1, INT_MAX);
    
    dis[s]= 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

    q.push({0, s});

    while(!q.empty()) {
      pair<int, int> p= q.top();
      q.pop();
      int dis_p= p.first;
      int val_p= p.second;

      for(auto child: arr[val_p]) {
          int val_c= child.first;
          int dis_c= child.second;

          if(dis[val_c] > dis[val_p] + dis_c) {
             dis[val_c]= dis[val_p] + dis_c;
             q.push({dis[val_c], val_c});
          }
      }
    }
    return dis;
  }
   

  //MODIFIED DFS 
  void topo_sort(vector<pair<int, int>> arr[], int s, vector<int> &ans, vector<bool> &visited) {
    visited[s]= true;

    for(auto child: arr[s]) {
       if(visited[child.first]== false) {
        topo_sort(arr, child.first, ans, visited);
       }
    }
    ans.push_back(s);
  }


  //shortest path in a DAG
  //(we can do this in a better time using topo sort and bfs logic)
  
  vector<int> shortest_dis_DAG(vector<pair<int, int>> arr[], int n, int s) {

    vector<int> dis(n+1, INT_MAX); 

    //step1 (FIND THE TOPO SORT)
    vector<int> tp;
    vector<bool> visited(n+1, false);
    topo_sort(arr, 1, tp, visited);

    reverse(tp.begin(), tp.end());
    //step 2(access the topo sort in BFS fashion)
    for(int i=0; i< tp.size(); i++) cout<<tp[i]<<" ";
    cout<<endl;

    dis[s]= 0;      

    for(int i=0; i< n; i++) {
         int par= tp[i];
         if(par!= INT_MAX) {
              //ACCESS THE CHILD OF THIS par 
              for(auto child: arr[par]) {
                    int val_c= child.first;
                    int dis_c= child.second;
                    if(dis[val_c]> dis[par] + dis_c) {
                      dis[val_c]= dis[par] + dis_c;
                    }
              }
         }
    }
    return dis;
  }


int main() {
    
    //n => Number of vertices
    //e => Number of edges

    int n, e;
    cin>>n>>e;

    
    vector<pair<int, int>> arr[n+1];

    for(int i=0; i< e; i++) {
    	int x, y, z;
    	cin>>x>>y>>z;

    	arr[x].push_back({y, z});
    	//arr[y].push_back({x, z});
    }

    vector<int> dis= shortest_dis_DAG(arr, n, 1);
    for(int i=0; i< dis.size(); i++) cout<<dis[i]<<" "; 
        
	return 0;
}
