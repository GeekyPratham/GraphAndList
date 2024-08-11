#include <iostream>
#include <list>
#include <vector>
#include <unordered_set>
using namespace std;
vector<list<int> > graph;// global graph

int v; // total no of vertexes
void add_edge(int src ,int dest,bool bi_dir = true){// src se dest ki taraf ek edge lagai hai matalb pint kia hai list ma
    graph[src].push_back(dest);
    if(bi_dir == true){
        graph[dest].push_back(src);
    }
}

unordered_set<int> visited;

bool dfs(int curr,int end){

    // base case
    if(curr==end) return true;
    visited.insert(curr);
    for(auto neighbour : graph[curr]){
        if(not visited.count(neighbour)){
            bool result = dfs(neighbour,end);
            if(result) return true;
        }
    }
    return false;
}
bool any_Path(int src,int dest){
    return dfs(src,dest);
}


int main(){

    cin>>v; // kitna vertex hai graph me
    graph.resize(v,list<int> ());

    int e; // no of edges
    cin>>e;
    visited.clear();
    while(e--){
        int src,dest;
        cin>>src>>dest;

        add_edge(src,dest);
    }
    int x,y;
    cin>>x>>y;
    cout<<any_Path(x,y);

    return 0;
}