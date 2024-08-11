// given a undirected weighted graph along with a src and destination . find the shortest path between src and dest in terms of sum and edge width

#include <bits/stdc++.h>
#define pp pair<int,int>
#define ll long long int
using namespace std;
vector<list<pp> > gr;
void add_edge(int u,int v,int wt,bool bidir = true){
    gr[u].push_back({v,wt});
    if(bidir){
        gr[v].push_back({u,wt});
    }
}

ll dijkstra(int src,int dest,int n){ //total time complexity = O(vlogv + elogv)
    // src->source , dest->destination, n -> no of vertices
    priority_queue< pp ,vector<pp> ,greater<pp> > pq;
    pq.push({0,src});
    // it stores pair of->(wt,neighbor)
    unordered_set<int> visited;//it store the which is visited at the time of pop;
    vector<int> via(n+1); // it stores that which node visited from which node
    unordered_map<int,int> mp;
    //it stores the (node,its total dist from source)
    mp[0]=0;//as 0 is src then distance to reach source from source is 0;

    for(int i=1;i<n;i++){ //O(v)
        mp[i]=INT_MAX;//initially distance from src of each node
    }
    while(!pq.empty()){ //O((V+E)logV)
        pp curr = pq.top();
        if(visited.count(curr.second)){
            pq.pop();
            continue;
        }
        visited.insert(curr.second);
        pq.pop();
        for(auto neighbor : gr[curr.second]){//neighbor.first->destination and neighbor.second->weight
            if(!visited.count(neighbor.first) && mp[neighbor.first]>(mp[curr.second]+neighbor.second)){
                pq.push({neighbor.second,neighbor.first});
                via[neighbor.first]=curr.second;
                mp[neighbor.first]=mp[curr.second]+neighbor.second;
            }
        }
    }
    return mp[dest];
}

int main(){
    int n,m;
    cin>>n>>m;
    gr.resize(n,list<pp> ());
    while(m--){
        int u,v,wt;
        cin>>u>>v>>wt;
        add_edge(u,v,wt);
    }
    int src,dest;
    cin>>src>>dest;
    cout<<dijkstra(src,dest,n);
    return 0;
}

//testcase

// 7 9
// 0 1 1
// 0 2 5
// 1 2 4
// 1 3 1
// 2 4 1
// 3 6 2
// 3 4 1
// 4 5 5
// 6 5 1



