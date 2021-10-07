//BFS
//Use Queue
//Time Comp:O(V+E) with  Adjacency List and O(V^2) with Adjacency Matrix
//Space Comp:O(V)

/*
        1            3
      /   \          |
    10     8         7
      \   /        /    \
        9  ------ 0 ---- 10
                     
*/ 
#include<bits/stdc++.h>
using namespace std;

void bfs(vector<int> adj[],int s,int n){

    queue<int> q;
    vector<int> visited(n,0);
    
    vector<int> ans;
    
    q.push(s);
    visited[s]=1;

    while(!q.empty()){
        int a=q.front();
        ans.push_back(a);
        q.pop();
        for(auto i:adj[a]){
            
            if(!visited[i]){
                visited[i]=1;
                q.push(i);
            }
        }
    }
    
    for(auto i:ans){
        cout<<i<<" ";
    }
    
}

void addEdge(vector<int> adj[],int u,int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}


int main(){
    
    vector<int> adj[12];
    addEdge(adj,0,9);
    addEdge(adj,0,7);
    addEdge(adj,0,11);
    addEdge(adj,1,10);
    addEdge(adj,1,8);
    addEdge(adj,3,7);
    addEdge(adj,7,11);
    addEdge(adj,8,9);
    addEdge(adj,9,10);
    
    bfs(adj,0,12);
    
    return 0;
}
