#include <bits/stdc++.h>
using namespace std;

// adjacency list banana hai 
// isme array of list hoga
vector<list<int> > graph;

int v; // total no of vertices

void add_edge(int src,int dest,bool bi_dir = true){
    graph[src].push_back(dest);// src se dest ki taraf ek edge lagai hai matalb pint kia hai list ma
    if(bi_dir == true){
        //agar  bidirectional /undirected graph hai toh
        // tm source se destination ki taraf bhi ek edge lagao ga
        graph[dest].push_back(src);
    }
}

void topoBFS(){
    vector<int> indegree(v,0);

    // graph me travell karke indegreee wala array bhare ge


    for(int i=0;i<v;i++){
        for(auto neighbour : graph[i]){
            // i ---> neghbour
            indegree[neighbour]++;
        }
    }

    queue<int> q;
    unordered_set<int> visited;
    for(int i=0;i<v;i++){
        if(indegree[i]==0 ) {
            visited.insert(i);
            q.push(i);
        }
    }

    while(!q.empty()){
        int node = q.front();
        cout<<node<<" ";
        q.pop();
        for(auto neighbor : graph[node]){ // ish node ka sara neighbor pa jaiga
            if(! visited.count(neighbor)){
                indegree[neighbor]--;
                if(indegree[neighbor]==0){
                    visited.insert(neighbor);
                    q.push(neighbor);
                }
            }
        }

    }

    
}

void display(){

    for(int i=0;i<graph.size();i++){
        cout<<i<<"->";
        for(auto el : graph[i]){
            cout<<el<<" ,";
        }
        cout<<endl;
    }
    cout<<endl;
}
int main(){

    cin>>v; // kitna vertex hai graph mai
    graph.resize(v,list<int> ());

    int e;
    cin>>e; //enter no of edges

    while(e--){
        int src,dest;
        cin>>src>>dest;
        add_edge(src,dest,false);
    }
    cout<<"starting Bfs"<<endl;
    topoBFS();

}

