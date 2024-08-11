#include <iostream>
#include <list>
#include <vector>
#include <unordered_map>
using namespace std;
// adjacency list banana hai 
// isme array of list hota hai 

vector<unordered_map<int,int> > graph;// global graph

int v; // total no of vertexes
void add_edge(int src ,int dest,int wt,bool bi_dir = true){
    graph[src][dest]=wt;// src se dest ki taraf ek edge lagai hai matalb pint kia hai list ma
    if(bi_dir == true){
        //agar  bidirectional /undirected graph hai toh
        // tm source se destination ki taraf bhi ek edge lagao ga
        graph[dest][src]=wt;
    }
}
void display(){

    for(int i=0;i<graph.size();i++){
        cout<<i<<"->";
        for(auto el : graph[i]){
            cout<<"("<<el.first<<","<<el.second<<")"<<" ,";
        }
        cout<<endl;
    }
    cout<<endl;
}


int main(){

    cin>>v; // kitna vertex hai graph me
    graph.resize(v,unordered_map<int,int> ());

    int e; // no of edges
    cin>>e;

    while(e--){
        int src,dest,wt;
        cin>>src>>dest>>wt;
        add_edge(src,dest,wt,true);// for undirected graph
        // add_edge(src,dest,wt,false);// for weighted graph
    }
    display();

    return 0;
}