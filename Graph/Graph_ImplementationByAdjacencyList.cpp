#include <iostream>
#include <list>
#include <vector>
using namespace std;
// adjacency list banana hai 
// isme array of list hota hai 

vector<list<int> > graph;// global graph

int v; // total no of vertexes

void add_edge(int src ,int dest,bool bi_dir = true){
    graph[src].push_back(dest);// src se dest ki taraf ek edge lagai hai matalb pint kia hai list ma
    if(bi_dir == true){
        //agar  bidirectional /undirected graph hai toh
        // tm source se destination ki taraf bhi ek edge lagao ga
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


int main(){

    cin>>v; // kitna vertex hai graph me
    graph.resize(v,list<int> ());

    int e; // no of edges
    cin>>e;

    while(e--){
        int src,dest;
        cin>>src>>dest;
        // add_edge(src,dest,true);// for undirected graph
        add_edge(src,dest,false);// for weighted graph
    }
    display();

    return 0;
}