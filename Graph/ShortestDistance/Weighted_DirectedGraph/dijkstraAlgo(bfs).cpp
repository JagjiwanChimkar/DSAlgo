//Dijkstra's Algo (BFS)
//Instead of Queue,We use Min Priority queue, As it take node with according to 
//which one with shortest path from starting node. 

//Time Comp:O(V+E)
//Space Comp:O(V)

/*
    0-----2----5
     \    |   /
       4  |  /
        \ | /
          3 
*/

#include<bits/stdc++.h>
using namespace std;


void dijkstra(vector<pair<int,int>> adj[],int src,vector<int> &shortDist){
    shortDist[src]=0;
    
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
    q.push({shortDist[src],src});
    
    while(!q.empty()){
        pair<int,int> s=q.top();
        q.pop();
        
        for(auto i:adj[s.second]){
            if(shortDist[s.second]+i.second<shortDist[i.first]){
                shortDist[i.first]=shortDist[s.second]+i.second;
                q.push({shortDist[i.first],i.first});
            }
        }
    }
}

void addEdge(vector<pair<int,int>> adj[], int u, int v,int wt){
    adj[u].push_back({v,wt});
}

void printGraph (vector<pair<int,int>> adj[], int V){
  for (int v = 0; v < V; ++v){
      cout << "\n Adjacency list of vertex " << v << "\n head ";
    for (auto x:adj[v]){
	  cout << "-> (" <<x.first<<","<<x.second<<")";
      printf ("\n");
    }
  }
}

int main (){

  vector<pair<int,int>> adj[6];

  addEdge(adj,1,2,2);
  addEdge(adj,1,4,1);
  addEdge(adj,2,1,2);
  addEdge(adj,2,3,4);
  addEdge(adj,2,5,5);
  addEdge(adj,3,2,4);
  addEdge(adj,3,3,3);
  addEdge(adj,3,5,1);
  addEdge(adj,4,1,1);
  addEdge(adj,4,3,3);
  addEdge(adj,5,2,5);
  addEdge(adj,5,3,1);
 
  
  //printGraph(adj,6);

  vector<int> shortDist(6,INT_MAX);
  
  dijkstra(adj,1,shortDist);
  
  cout<<"shortDist :";
  for(int i=1;i<shortDist.size();i++){
      cout<<shortDist[i]<<" ";
  }
  
  
  return 0;
}



