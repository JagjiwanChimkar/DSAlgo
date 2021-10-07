//BFS

//Time Comp:O(V+E)
//Space Comp:O(V)
#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[],int u,int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void bfs(vector<int> adj[],int s,int n){

    queue<int> q;
    vector<int> visited(n,0);
    
    vector<int> bfs;
    
    q.push(s);
    visited[s]=1;
    while(!q.empty()){
        int a=q.front();
        bfs.push_back(a);
        q.pop();
        for(auto i:adj[a]){
            
            if(!visited[i]){
                visited[i]=1;
                q.push(i);
            }
        }
    }
    
    for(auto i:bfs){
        cout<<i<<" ";
    }
    
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
