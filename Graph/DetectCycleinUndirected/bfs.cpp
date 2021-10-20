//Detect Cylce in Undirected Graph using BFS
//If current's node adjacent node is visited and not same as it's parent node
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

void CheckCycle_bfs(vector<int> adj[],int s,int n){
    queue<pair<int,int>> q;     // pair<current node,parent node>
    vector<int> visited(n,0);
    pair<int,int> p(s,-1);
    q.push(p);
    
    while(!q.empty()){
        pair<int,int> a=q.front();
        q.pop();
        
        for(auto i:adj[a.first]){
            
            if(!visited[i]){
                visited[i]=1;
                q.push({i,a.first});
            }else if(i!=a.second){
                    cout<<"cycle detected at vertex : "<<i;
                    return;
                }
            
        }
        
    }
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
    addEdge(adj,7,8);
    addEdge(adj,8,9);
    addEdge(adj,8,11);
    addEdge(adj,9,10);
    // printGraph(adj, 12);

    CheckCycle_bfs(adj,3,12);
    
    return 0;
}
