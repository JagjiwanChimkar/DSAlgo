//Find Shortest Path from src to dest fro Weigthed UnDirected Graph
//Dijkstra's algo
//Use parent array for storing a vertex's previous vertex whose short Dist is calculated 
//then Recursively call a printPath function(dest<=parent[dest])

//Time Comp:O((V+E)logV)
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

void printPath(int src,int dest,vector<int> parent){
        if(dest==src){
            return;
        }    
        
        printPath(src,parent[dest],parent);
        cout<<parent[dest]<<"->";
}

void dijkstra(vector<pair<int,int>> adj[],int src,vector<int> &shortDist,int n,int dest){
    shortDist[src]=0;
    
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
    q.push({shortDist[src],src});
    
    vector<int> parent(n);
    parent[src]=-1;
    
    while(!q.empty()){
        pair<int,int> s=q.top();
        q.pop();
        
        for(auto i:adj[s.second]){
            if(shortDist[s.second]+i.second<shortDist[i.first]){
                shortDist[i.first]=shortDist[s.second]+i.second;
                q.push({shortDist[i.first],i.first});
                parent[i.first]=s.second;
            }
        }
    }
    
    cout<<"Shortest path from "<<src<<" to "<<dest<<" : \n"; 
    printPath(src,dest,parent);
    cout<<dest;
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
  
  dijkstra(adj,1,shortDist,6,5);
  
  
  return 0;
}




