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

int main(){
  
    DisjointSet d1(7);
    d1.union_(0,1);
    d1.union_(2,3);
    d1.union_(3,4);
    d1.union_(3,6);
    d1.union_(1,5);

    for(int i=0;i<7;i++){
        cout<<"parent["<<i<<"] : "<<d1.findParent(i)<<endl;
    }
    
}