#include <iostream>
#include <list>
#include <vector>
#include <unordered_set>

using namespace std;

vector<list<int> > graph;

int v;
void add_edge(int src ,int dest,bool bi_dir = true){
    graph[src].push_back(dest);
    if(bi_dir == true){
        graph[dest].push_back(src);
    }
}

void dfs(int node ,unordered_set<int>& visited){
    visited.insert(node);
    for(auto neighbor : graph[node]){
        if(! visited.count(neighbor)){
            dfs(neighbor,visited);
        }
    }
}

int connected_component(){
    int count = 0;
    unordered_set<int> visited;
    for(int i=0;i<v;i++){
        // ham ek ek kar ka sare vertices par jaige
        // agar koi vertex se ham log ko fir se dfs initialise karna pada toh ham log ka connected component 1 se increase kar jaiga
        if(visited.count(i)==0){
            count++;
            dfs(i,visited);
            
        }
       
    }
     return count;
}

int main(){

    cin>>v;
    graph.resize(v,list<int> ());

    int e;
    cin>>e;

    while(e--){
        int src,dest;
        cin>>src>>dest;
        add_edge(src,dest,false);
    }

    cout<<connected_component();
    return 0;
}