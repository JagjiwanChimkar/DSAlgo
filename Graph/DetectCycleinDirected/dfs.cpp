//Detect Cylce in 'Directed' Graph using DFS
//Need to use extra dfsvisited array and mark 0 id backtrack
//Cycle detected => visited[i]==dfsvisited[i] (where i is element of adj[s])

//Time Comp:O(V+E)
//Space Comp:O(V)



/*
    1->-2->--3->--4
        ^    |    |
        7    6->--5
       / ^
      8->-9

*/

#include<bits/stdc++.h>
using namespace std;

bool dfs(vector<int> adj[],int s,int n,vector<int> &visited,vector<int> &dfsvisited){
   visited[s]=1,dfsvisited[s]=1;
   
   for(auto i : adj[s]){
       if(!visited[i]){
           if(dfs(adj,i,n,visited,dfsvisited)){
               return true;
           }
       }else if(visited[i]==dfsvisited[i]){
           return true;
       }
   }
   dfsvisited[s]=0;
   return false;
}

void addEdge(vector<int> adj[],int u,int v){
    adj[u].push_back(v);
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
    
    vector<int> adj[10];

    addEdge(adj,1,2);
    addEdge(adj,2,3);
    addEdge(adj,3,4);
    addEdge(adj,3,6);
    addEdge(adj,4,5);
    addEdge(adj,6,5);
    addEdge(adj,7,2);
    addEdge(adj,7,8);
    addEdge(adj,8,9);
    addEdge(adj,9,7);
    
    //printGraph(adj, 12);

    vector<int> visited(10,0);
    vector<int> dfsvisited(10,0);

    for(int i=1;i<10;i++){         //As directed,to avoid block end
        if(!visited[i]){
            if(dfs(adj,i,10,visited,dfsvisited)){
               cout<<"Cycle Detected";
            }
        }
    }
   
    
    return 0;
}

