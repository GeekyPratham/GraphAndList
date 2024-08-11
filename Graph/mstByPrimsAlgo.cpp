/*
pirms algorithm

-> in this we have given an weighted and undirected graph
-> we have given a source point from where we have to apply bfs
-> we will make a unordered_map of discoveryWeight and parent
-> we need a min heap priority queue of <weight , parent> 
-> we have to maintain the set of visited 

steps->
- we will insert the <-1,src> in the priority queue
- we will remove the root of priority queue one by one
- if the root element is already visited then contiue
_ else we marked the element visited 
- store the wt of the pair in the answer
- update the mapping 
- go to every neighbor of current element and only add those in the priority queue which are not visited and have better weight proposition

*/
#include <bits/stdc++.h>
#define ll long long int
#define pp pair<int,int>
using namespace std;

vector<list<pp>> gr;

void add_edge(int u, int v, int wt, bool bidir = true) {
    gr[u].push_back({v, wt});
    if (bidir) {
        gr[v].push_back({u, wt});
    }
}

ll prims(int src, int n) {
    priority_queue<pp, vector<pp>, greater<pp>> pq;
    unordered_set<int> visited;
    vector<int> par(n + 1);
    unordered_map<int, int> mp;
    for (int i = 1; i <= n; i++) {
        mp[i] = INT_MAX;
    }
    pq.push({0, src});
    mp[src] = 0;

    ll result = 0; // Changed to long long
    while (!pq.empty()) {
        pp curr = pq.top();
        pq.pop();
        int node = curr.second;
        int wt = curr.first;
        
        // Skip if already visited
        if (visited.count(node))
            continue;
        
        visited.insert(node);
        result += wt;

        for (auto neighbor : gr[node]) {
            int v = neighbor.first;
            int wt = neighbor.second;
            if (!visited.count(v) && mp[v] > wt) {
                pq.push({wt, v});
                par[v] = node;
                mp[v] = wt;
            }
        }
    }
    return result;
}

int main() {
    int n, m;
    cin >> n >> m;
    gr.resize(n + 1);
    while (m--) {
        int u, v, wt;
        cin >> u >> v >> wt;
        add_edge(u, v, wt);
    }
    int src;
    cin >> src;
    cout << prims(src, n);

    return 0;
}
