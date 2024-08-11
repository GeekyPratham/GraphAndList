// this code does not give me correct output


#include <iostream>
#include <list>
#include <queue>
#include <vector>
#include <unordered_set>
using namespace std;
// adjacency list banana hai 
// isme array of list hota hai 

vector<list<pair<int,string> > > graph;// global graph

int v; // total no of vertexes

void add_edge(int src ,int dest,string color,bool bi_dir = true){
    graph[src].push_back({dest,color});
    if(bi_dir == true){
        graph[dest].push_back({src,color});
    }
}
void display(){

    for(int i=0;i<graph.size();i++){
        cout<<i<<"->";
        for(auto el : graph[i]){
            pair<int,string> temp = el;
            cout<<temp.first<<"("<<temp.second<<")"<<",";
        }
        cout<<endl;
    }
    cout<<endl;
}


int main(){

    cin>>v; // kitna vertex hai graph me
    graph.resize(v);

    int e; // no of edges
    cin>>e;

    while(e--){
        int src,dest;
        string ch;
        cin>>src>>dest>>ch;
        add_edge(src,dest,ch,false);
    }
    // display();

    int src,dest;
    cin>>src>>dest;

    // we have to find first intermediate node
    queue<int> q;
    queue<int> qu;
    unordered_set<int> visited1;
    unordered_set<int> visited2;
    for(int i=0;i<graph.size();i++){
        bool flag1 = false;
        bool flag2 = false;
        for(auto el : graph[i]){
            pair<int,string> temp = el;
            if(temp.second == "red") flag1=true;

            if(temp.second == "blue") flag2 = true;
            if(flag1==true && flag2==true){
                if(i!=src){
                    qu.push(i);
                    q.push(i);
                    visited1.insert(i);
                    visited2.insert(i);
                }
                
                break;
            }
        }
    }
    // check intermediate nodes
    while(!qu.empty()){
        cout<<qu.front()<<" ";
        qu.pop();
    }
    cout<<endl;

    q.push(-1);
    qu.push(-1);
    // go to the source from intermediate node using red line applying bfs
    
    int dist1 = 0;
    while(!q.empty()){
        int num = q.front();
        q.pop();
        if(num==src){
            break;
        }
        if(num==-1){
            if(!q.empty()){
                dist1++;
                q.push(-1);
            }
            else{
                cout<<"not found source";
                dist1 = 0;
                break;
            }
        }
        for(auto neighbor : graph[num]){
            pair<int,string> temp = neighbor;
            if(!visited1.count(temp.first)){
                if(temp.second=="red"){
                    q.push(temp.first);
                    visited1.insert(temp.first);
                }   
            }
            
        }
    }

    // go to the destination from intermediate node using blue line applying bfs
    
    int dist2 = 0;
    while(!qu.empty()){
        int num = qu.front();
        qu.pop();
        if(num==dest){
            break;
        }
        if(num==-1){
            if(!qu.empty()){
                dist2++;
                qu.push(-1);
            }
            else{
                cout<<"not found source";
                dist2 = 0;
                break;
            }
        }
        for(auto neighbor : graph[num]){
            pair<int,string> temp = neighbor;
            if(!visited2.count(temp.first)){
                if(temp.second=="blue"){
                    q.push(temp.first);
                    visited2.insert(temp.first);
                }   
            }
        }
    }

    cout<<dist1+dist2+2;

    return 0;
}


// 7
// 9
// 0 1 red
// 0 2 red
// 0 3 blue
// 1 4 red
// 2 3 red
// 3 4 blue
// 3 5 blue
// 4 5 blue 
// 5 6 blue

// 7
// 18
// 0 1 red
// 0 2 red
// 0 3 blue
// 1 4 red
// 2 3 red
// 3 4 blue
// 3 5 blue
// 4 5 blue 
// 5 6 blue
// 1 0 red
// 2 0 red
// 3 0 blue 
// 4 1 red
// 3 2 red
// 4 3 blue
// 5 3 blue
// 5 4 blue
// 6 5 blue

// 0->1(red),2(red),3(blue),
// 1->4(red),0(red),
// 2->3(red),0(red),
// 3->4(blue),5(blue),0(blue),2(red),
// 4->5(blue),1(red),3(blue),
// 5->6(blue),3(blue),4(blue),
// 6->5(blue),

// 
// jisme dono color present hai wahi mera intermediate node hoga