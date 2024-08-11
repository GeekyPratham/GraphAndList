#include <iostream>
#include <list>
#include <vector>
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
bool dfs(int src,int parent,unordered_set<int> &vis){
    vis.insert(src);
    
    for(auto neighbor : graph[src]){
        if(vis.count(neighbor) && neighbor!=parent){
            return true;
            //cycle detected
        }
        if(!vis.count(neighbor)){
            bool result = dfs(neighbor,src,vis);
            if(result==true) return true;
        }
    }
    return false;
}
bool has_cycle(){
    unordered_set<int> visited;
    for(int i=0;i<v;i++){// yaha ham har vertex ka lia graph chala raha hai kyoki ham man rahe hai ki disconnected graph bhi ho sakta hai hamara
        if(!visited.count(i)){
            bool result = dfs(i,-1,visited);
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