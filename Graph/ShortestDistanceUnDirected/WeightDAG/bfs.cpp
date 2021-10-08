//Find Shortest Distance of each node from src in Weigthed DAG

//First find TopoSort using dfs
//Then using iterating topoSort stack,cal shortDist using bfs

//Time Comp:O(V+E)
//Space Comp:O(V)

/*
    
*/

#include<bits/stdc++.h>
using namespace std;

void topoSort(vector<pair<int,int>> adj[],int s,int n,stack<int> &stk,vector<int> &visited){
    visited[s]=1;
    for(auto i:adj[s]){
        if(!visited[i.first]){
            visited[i.first]=1;
            topoSort(adj,i.first,n,stk,visited);
        }
    }
    stk.push(s);
}

void cal_ShortDist(vector<pair<int,int>> adj[],stack<int> &stk,vector<int> &shortDist){
    while(!stk.empty()){
        int s=stk.top();
        stk.pop();

        for(auto i:adj[s]){
            if(shortDist[s]+i.second<shortDist[i.first]){
                shortDist[i.first]=shortDist[s]+i.second;
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

  addEdge(adj, 0,1,2);
  addEdge(adj, 0,4,1);
  addEdge(adj, 1,2,3);
  addEdge(adj, 2,3,6);
  addEdge(adj, 4,2,2);
  addEdge(adj, 4,5,4);
  addEdge(adj, 5,3,1);
 
  
  //printGraph(adj,6);

  stack<int> stk;
  vector<int> visited(6,0);
  
  topoSort(adj,0,6,stk,visited);
  
  cout<<"stack : ";
  while(!stk.empty()){
      cout<<stk.top()<<" ";
      stk.pop();
  }
  cout<<endl;
  
  vector<int> shortDist(6, INT_MAX);
  shortDist[stk.top()]=0;
  cal_ShortDist(adj,stk,shortDist);
  
  cout<<"shortDist :";
  for(auto i:shortDist){
      cout<<i<<" ";
  }
  
  
  return 0;
}

