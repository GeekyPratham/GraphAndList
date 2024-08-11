

#include <iostream>
#include <list>
#include <vector>
#include <unordered_set>
#include <queue>
#include <math.h>
#include <climits>



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

void bfs(int src, vector<int>& dist){
    queue<int> q;
    visited.clear();
    dist.resize(v,INT_MAX);
    dist[src] = 0;
    visited.insert(src);
    q.push(src);
    while(!q.empty()){
        int curr = q.front();
        cout<<curr<<" ";
        q.pop();
        for(auto neighbour : graph[curr]){
            if(! visited.count(neighbour)){
                q.push(neighbour);
                visited.insert(neighbour);
                dist[neighbour]=dist[curr]+1;// it signifies that the parent of neighbour is current
            }
        }
        
    }
    cout<<endl;

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
    int x;
    cin>>x;
    
    vector<int> dist;
    bfs(x,dist);
    
    for(int i=0;i<dist.size();i++){
        cout<<dist[i]<<" ";
    }

    return 0;
}