//Topological Sorting using DFS only on DAG
//Use Stack 

//Time Comp:O(V+E)
//Space Comp:O(V)


/*
    5-->--0--<--4
    ^           |
    |           |
    2-->--3-->--1
*/

#include<bits/stdc++.h>
using namespace std;

void dfs(vector<int> adj[],int s,vector<int> &visited,stack<int> &stk){
   visited[s]=1;
   
   for(auto i:adj[s]){
       if(!visited[i]){
           dfs(adj,i,visited,stk);
       }
   }
   
   stk.push(s);
}

stack<int> TopoSort(vector<int> adj[],int n){
    vector<int> visited(n,0);
    stack<int> stk;
    
    for(int i=0;i<n;i++){
        if(!visited[i]){
            dfs(adj,i,visited,stk);
        }
    }
    return stk;
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
    
    vector<int> adj[6];

    addEdge(adj,2,3);
    addEdge(adj,3,1);
    addEdge(adj,4,0);
    addEdge(adj,4,1);
    addEdge(adj,5,0);
    addEdge(adj,5,2);
   
    //printGraph(adj, 6);

    stack<int> stk=TopoSort(adj,6);
   
    while(!stk.empty()){
        cout<<stk.top()<<" ";
        stk.pop();
    }
    return 0;
}

