#include<bits/stdc++.h>
using namespace std;

class edge{
    public:
        int u,v,w;
        edge(int u,int v,int w){
            this->u=u;
            this->v=v;
            this->w=w;
        }
};

void bellmanFord(vector<edge> g,int V,int E){
    int path[V];
    path[0]=0;
    for(int i=1;i<V;i++){
        path[i]=INT_MAX;
    }

    for(int i=0;i<V-1;i++){
        for(int j=0;j<E;j++){
            int u=g[j].u;
            int v=g[j].v;
            int w=g[j].w;
            path[v]=min(path[v],w+path[u]);
        }
    }

    for(int j=0;j<E;j++){
            int u=g[j].u;
            int v=g[j].v;
            int w=g[j].w;
            if(w+path[u]<path[v]){
				cout<<"Graph contains negative weight cycle"<<endl;
		 }	
    }

    for(int i=0;i<V;i++)
        cout<<path[i]<<" ";
}

int main(){
    int V=5;
    int E=8;
    vector<edge> g;

    g.push_back(edge(0,1,-1));
    g.push_back(edge(0,2,4));
    g.push_back(edge(1,2,3));
    g.push_back(edge(1,3,2));

    g.push_back(edge(1,4,2));
    g.push_back(edge(3,2,5));
    g.push_back(edge(3,1,1));
    g.push_back(edge(4,3,-3));

    bellmanFord(g,V,E);
}