#include<bits/stdc++.h>
using namespace std;

class DisjointSet{
    public:
        vector<int> rank;
        vector<int> parent;
    
        DisjointSet(int n){
            for(int i=0;i<n;i++){
                rank.push_back(0);
                parent.push_back(i);
            }
        }

        int findParent(int node){
            if(parent[node]==node){
                return node;
            }
            return parent[node]=findParent(parent[node]);
        }

        void union_(int u,int v){
            u=findParent(u);
            v=findParent(v);

            if(rank[u]<rank[v]){
                parent[u]=v;
            }
            else if(rank[u]>rank[v]){
                parent[v]=u;
            }else{
                parent[v]=u;
                rank[u]++;
            }
        }

        

};

class node{
   public:
        int wt,u,v;
        node(int wt,int u,int v){
            this->wt=wt;
            this->u=u;
            this->v=v;
        }

};

bool comp(node a,node b){
    return a.wt<b.wt;
}

int main(){
    DisjointSet d1(7);
    vector<node> edges;
    
    int n;
    cout<<"Enter N: ";
    cin>>n;

    edges.push_back(node(1,1,4));
    edges.push_back(node(2,1,2));
    edges.push_back(node(3,2,3));
    edges.push_back(node(9,4,5));
    edges.push_back(node(4,1,5));
    edges.push_back(node(5,3,4));
    edges.push_back(node(3,2,4));
    edges.push_back(node(7,2,6));
    edges.push_back(node(8,3,6));

    sort(edges.begin(),edges.end(),comp);

    vector<pair<int,int>> mst;

    for(auto i:edges){
        if(d1.findParent(i.u)!=d1.findParent(i.v)){
            mst.push_back({i.u,i.v});
            d1.union_(i.u,i.v);
        }
    }

    for(auto i:mst){
        cout<<"{"<<i.first<<","<<i.second<<"}"<<endl;
    }
    
}