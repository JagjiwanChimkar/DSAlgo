//Find Shortest Distance of each node from src-node in UnDirected Graph 
//Take Weight of each Edge as 1
//Use BFS

//Time Comp:O(V+E)
//Space Comp:O(V)


/*     
     / 1---- 2    7
    0  |      \  /  \
     \ 3--4--5--6----8  
*/

#include<bits/stdc++.h>
using namespace std;

void bfs(vector<int> adj[],int s,vector<int> &shortDist){
   queue<int> q;
   q.push(s);
   shortDist[s]=0;
   while(!q.empty()){
        int s=q.front();
        q.pop();
        
        for(auto i:adj[s]){
            if(shortDist[s]+1<shortDist[i]){      //Note 
                shortDist[i]=shortDist[s]+1;
                q.push(i);
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
    
    vector<int> adj[9];

    addEdge(adj,0,1);
    addEdge(adj,0,3);
    addEdge(adj,1,2);
    addEdge(adj,1,3);
    addEdge(adj,2,6);
    addEdge(adj,3,4);
    addEdge(adj,4,5);
    addEdge(adj,5,6);
    addEdge(adj,6,7);
    addEdge(adj,6,8);
    addEdge(adj,7,8);
    
    //printGraph(adj,9);
    
    vector<int> shortDist(9,INT_MAX);
    bfs(adj,0,shortDist);
    
    for(auto i:shortDist){
        cout<<i<<" ";
    }
    return 0;
}


