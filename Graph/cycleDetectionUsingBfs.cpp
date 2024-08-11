#include <iostream>
#include <list>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;
vector<list<int> > graph;// global graph
int v; 

void add_edge(int src ,int dest,bool bi_dir = true){
    graph[src].push_back(dest);
    if(bi_dir == true){
        graph[dest].push_back(src);
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
bool bfs(int src){
    unordered_set<int> visited;
    queue<int> q;
    vector<int> parent(v,-1);
    visited.insert(src);
    q.push(src);
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        for(auto neighbor : graph[curr]){
            
            if(visited.count(neighbor)>0 && parent[curr]!=neighbor){
                return true;
            }
            if(!visited.count(neighbor)){
                visited.insert(neighbor);
                q.push(neighbor);
                parent[neighbor]=curr;
            }
        }
    }
    return false;
}
bool has_cycle(){
    unordered_set<int> visited;
    for(int i=0;i<v;i++){// yaha ham har vertex ka lia graph chala raha hai kyoki ham man rahe hai ki disconnected graph bhi ho sakta hai hamara
        if(!visited.count(i)){
            bool result = bfs(i);
            if(result == true) return true;
        }
    }
    return false;
}
int main(){
    cin>>v; 
    graph.resize(v,list<int> ());

    int e; // no of edges
    cin>>e;
    

    while(e--){
        int src,dest;
        cin>>src>>dest;
        add_edge(src,dest,false);
    }
    
    unordered_set<int> vis;
    bool final = has_cycle();
    if(final == true){
        cout<<"cycle detected"<<endl;
    }
    else {
        cout<<"cycle not present"<<endl;
    }

    return 0;
}