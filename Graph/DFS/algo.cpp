//DFS
//Use Recursion method

//Time Comp:O(V+E)
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

void dfs(vector<int> adj[],vector<int> &visited,int s,int n,vector<int> &ans){
    ans.push_back(s);
    visited[s]=1;
    for(auto i:adj[s]){
        if(!visited[i]){
            dfs(adj,visited,i,n,ans);
        }
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
    
    vector<int> ans;
    vector<int> visited(12,0);
    dfs(adj,visited,0,12,ans);
    
    for(auto i:ans){
        cout<<i<<" ";
    }
    return 0;
}
