//Topological Sorting using BFS only on DAG
//Know as Kahn's Algorithm
//Use Queue and insert first whose Indegree is zero

//Time Comp:O(V+E)
//Space Comp:O(V)


/*
    5-->--0--<--4
    |     |     |
    2-->--3-->--1
*/

#include<bits/stdc++.h>
using namespace std;

void bfs(vector<int> adj[],vector<int> &Indegree,vector<int> &res,queue<int> q){
    
   while(!q.empty()){
       int s=q.front();
       q.pop();
       res.push_back(s);
       
       for(auto i:adj[s]){
            
           Indegree[i]--;        //Reduced the Indgree[i] once it traversed.
           
           if(!Indegree[i]){
               q.push(i);
           }
       }
   }
   
}

vector<int> TopoSort(vector<int> adj[],int n){
    vector<int> Indegree(n,0);
    vector<int> res;                   //result
    queue<int> q;
    
    for(int i=0;i<n;i++){              //creating Indegree Array and filling them
        for(auto j:adj[i]){
            Indegree[j]++;
        }
    }
    
    for(int i=0;i<n;i++){            //first push the element with 0 incoming arrow into queue
        if(!Indegree[i]){
            q.push(i);
        }
    }
    
    bfs(adj,Indegree,res,q);         
    
    return res;
    
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

    vector<int> res=TopoSort(adj,6);
    
    for(auto i:res){
        cout<<i<<" ";
    }
    
    return 0;
}

