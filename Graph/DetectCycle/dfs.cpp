//Detect Cylce in Undirected Graph using DFS
//If current's node next node is visited and not same as it's parent node
//then cycle is present in it.

//Time Comp:O(V+E)
//Space Comp:O(V)


/*

3--5--6--7
   |  |  |
  10--9--8--11

*/

#include<bits/stdc++.h>
using namespace std;

bool CheckCycle_dfs(vector<int> adj[],int s,int prev,int n,vector<int> &visited){
   visited[s]=1;
   for(auto i:adj[s]){
       if(!visited[i]){
           if(dfs(adj,i,s,n,visited)){
               return true;
           }
       }
       else if(prev!=i){
           return true;
       }
   }
   return false;
}

void addEdge(vector<int> adj[],int u,int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void printGraph(vector<int> adj[], int V)
{
    for (int v = 0; v < V; ++v)
    {
        cout << "\n Adjacency list of vertex "
             << v << "\n head ";
        for (auto x : adj[v])
           cout << "-> " << x;
        printf("\n");
    }
}

int main(){
    
    vector<int> adj[12];

    addEdge(adj,3,5);
    addEdge(adj,5,10);
    addEdge(adj,5,6);
    addEdge(adj,6,7);
    addEdge(adj,6,9);
    addEdge(adj,7,8);
    addEdge(adj,8,9);
    addEdge(adj,8,11);
    addEdge(adj,9,10);
    //printGraph(adj, 12);

    vector<int> visited(12,0);
    
    if(CheckCycle_dfs(adj,3,-1,12,visited)){
        cout<<"Cycle Detected";
    }else{
        cout<<"Cycle Not Detected";
    }
    
    return 0;
}
