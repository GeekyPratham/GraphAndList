#include <iostream>
#include <list>
#include <vector>
#include <unordered_set>
using namespace std;
vector<list<int> > graph;// global graph

vector<vector<int> > result;
int v; // total no of vertexes
void add_edge(int src ,int dest,bool bi_dir = true){// src se dest ki taraf ek edge lagai hai matalb pint kia hai list ma
    graph[src].push_back(dest);
    if(bi_dir == true){
        graph[dest].push_back(src);
    }
}

unordered_set<int> visited;

void dfs(int curr,int end,vector<int>& path){

    // base case
    if(curr==end) {
        path.push_back(curr);
        result.push_back(path);
        path.pop_back();
        return;
    }
    visited.insert(curr);
    path.push_back(curr);
    for(auto neighbour : graph[curr]){
        if(! visited.count(neighbour)){
            dfs(neighbour,end,path);
            
        }
    }
    path.pop_back();
    visited.erase(curr);
    return;
}
void all_Path(int src,int dest){
    vector<int> path;
    dfs(src,dest,path);
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
    vector<int> path;
    int x,y;
    cin>>x>>y;
    all_Path(x,y);

    for(int i=0;i<result.size();i++){
        for(int j=0;j<result[i].size();j++){
            cout<<result[i][j]<<"->";
        }
        cout<<endl;
    }

    return 0;
}