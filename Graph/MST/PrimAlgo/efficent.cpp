//Effient Approch
//Instead of iterating on key[] for finding vertex with minimum key[i]
//use Min Priority Queue with pair<key[i],i>

//Time Comp:O((V+E)*logV)
//Space Comp:O(V)


/*
   0---1---2
   | / | /
   |/  |/
   3   4
*/

#include<bits/stdc++.h>
using namespace std;

void Find_MST(vector<pair<int,int>> adj[],int n){
    vector<int> key(n,INT_MAX);
    vector<bool> MST(n,false);
    vector<int> parent(n,-1);
    
    key[0]=0;
    parent[0]=-1;

    priority_queue< pair<int,int> , vector<pair<int,int>> ,greater< pair< int,int >> > pq;
    pq.push({0,0});

    for(int i=0;i<n-1;i++){

        int a=pq.top().second;
        pq.pop();
        MST[a]=true;

        for(auto v:adj[a]){
            if(key[v.first]>v.second){
                key[v.first]=v.second;
                parent[v.first]=a;
                pq.push({key[v.first],v.first});
            }
        }
            
    }
    

    cout<<"parent : "<<endl;
    for(int i=0;i<n;i++){
        cout<<i<<" : "<<parent[i]<<endl;
    }

}

void addEdge(vector<pair<int,int>> adj[],int u,int v,int wt){
    adj[u].push_back({v,wt});
    adj[v].push_back({u,wt});
}

void printGraph(vector<pair<int,int>> adj[], int V)
{
    for (int v = 0; v < V; ++v)
    {
        cout << "\n Adjacency list of vertex "
             << v << "\n head ";
        for (auto x : adj[v])
           cout << "-> (" << x.first << "," <<x.second<<")";
        printf("\n");
    }
}

int main(){
    
    vector<pair<int,int>> adj[5];

    addEdge(adj,0,1,2);
    addEdge(adj,0,3,6);
    addEdge(adj,1,2,3);
    addEdge(adj,1,3,8);
    addEdge(adj,1,4,5);
    addEdge(adj,2,4,7);
   
   
    // printGraph(adj, 5);
    Find_MST(adj,5);

    return 0;
}

