//Making Changes in kahn's Algo(Topological sort using bfs)
//As we know,TopoSort using for only DAG,
//If TopoSort don't return all vertices then Graph is not DAG and it's contain Cycle.

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

bool bfs(vector<int> adj[],vector<int> &Indegree,int n,queue<int> q){
   int cnt=0;                          //Count number of element in TopoSort order
   while(!q.empty()){
       int s=q.front();
       q.pop();
       cnt++;                          //Instead of storing in ans  
       
       for(auto i:adj[s]){
            
           Indegree[i]--;
           
           if(!Indegree[i]){
               q.push(i);
           }
       }
   }
   
   if(cnt==n) return false;           //TopoSort Of DAG contain all it's verticies 
   return true;
   
}

bool TopoSort(vector<int> adj[],int n){
    vector<int> Indegree(n,0);

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
    
    return bfs(adj,Indegree,n,q);        
    
    
    
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
    
    vector<int> adj[12];

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

    if(TopoSort(adj,12)){
        cout<<"Cycle Detected";
    }else{
         cout<<"Cycle Not Detected";
    }
    
    
    
    return 0;
}

