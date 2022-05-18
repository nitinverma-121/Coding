#include<bits/stdc++.h>
using namespace std;

vector<int> parent(1000, -1);
vector<int> size(1000, 0);

//Make the Set
void make_set(int a) {
   parent[a]= a;
   size[a]= 1;
}

//Find The Parent
int find_set(int a) {
   if(parent[a]==a) return a; //if it is a single element
                              //it hisself is his parent

   return parent[a]= find_set(parent[a]); //path optimisation  
}

//Unite the sets
void union_set(int a, int b) {
   //Unite their Parents/Representative

   int p1= find_set(a);
   int p2= find_set(b);

   if(p1== p2) return; //if they are already in the same set
                       //dont do anything
   
   //make any one any ones parent
   //parent[p2]= p1;

   //(OPTIMISISATION CAN BE DONE BY MAKING USE OF UNION BY RANK/SIZE)
   //i.e rather than making anyone parent
   //make the node with the max size as parent

   if(size[p1]< size[p2]) swap(p1, p2); //making p1 size always big than p2
   parent[p2]= p1;
   //size of the p1 tree also has to be increased
   size[p1]= size[p1] + size[p2];  
}

//DETECT CYCLE USING DSU
bool iscycle(vector<vector<int>> edgelist, int n) {
   //i need a edge list here

   for(int i=0; i< edgelist.size(); i++) {
      int x= edgelist[i][0];
      int y= edgelist[i][1];

      //agar ye dono same set me 
      //lie krte hai mtlb
      //ki cycle hai

      int px= find_set(x);
      int py= find_set(y);

      if(px== py) return true; //their is a cycle
      union_set(x, y);
   }
   return false;
}

//kruskal algorithm
//start from the min weight and avoid making cycles
//to always start from min. weight sort the edge list
 
 void kruskal_algo(vector<vector<int>> edgelist, int n) {
   //sort the edge list 
   //on the basis of the edgewt

   sort(edgelist.begin(), edgelist.end(), 
      [&](vector<int> a, vector<int> b) {
               return a[2]< b[2];
   } );

   vector<vector<int>> MST;

   for(int i=0; i< edgelist.size(); i++) {
        int x= edgelist[i][0];
        int y= edgelist[i][1];
        int wt= edgelist[i][2];

        int px= find_set(x);
        int py= find_set(y);

        //if they are making cycle avoid it
        if(px== py) continue;

        //if they are from different set
        //unite them
        union_set(x, y);
        //and add them in the MST
        MST.push_back({x, y, wt});
   }

   cout<<endl;

   for(int i=0; i< MST.size(); i++) {
        int x= MST[i][0];
        int y= MST[i][1];
        int wt= MST[i][2];

        cout<<"("<<x<<","<<y<<")"<<wt<<" ";
        cout<<endl;
   }
 } 



int main() {

     int n, e;
     cin>>n>>e;
     vector<pair<int, int>> arr[n+1];

     vector<vector<int>> edgelist;  
     //0 th index pe x
     //1th index pe y
     //2nd index pe wt

     for(int i=0; i<= n; i++) make_set(i);

     for(int i=0; i< e; i++) {
        int x, y, z;
        cin>>x>>y>>z;
        edgelist.push_back({x, y, z});
        arr[x].push_back({y,z});
        arr[y].push_back({x,z});
     }
     kruskal_algo(edgelist, n); 
}





