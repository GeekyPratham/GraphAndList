#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int find(vector<int> &parent,int x){
    if(parent[x]==x) return x;
    return parent[x]=find(parent,parent[x]);
}

void Union(vector<int> &par,vector<int> &rank,int a,int b){
    a = find(par,a);
    b = find(par,b);
    if(a==b) return;
    if(rank[a]>=rank[b]){
        par[b]=a;
        rank[a]++;
    }
    else{
        par[a]=b;
        rank[b]++;
    }

}

struct Edge{
    int src;
    int dest;
    int wt;
};

bool cmp(Edge e1,Edge e2){
    return e1.wt <e2.wt;
}

ll kruskals(vector<Edge> &input,int n,int e){
   sort(input.begin(),input.end(),cmp);//sort on the basis of weight
   vector<int> parent(n+1);
   vector<int> rank(n+1,1);
   for(int i=0;i<=n;i++){
    parent[i]=i;
   }
   int edgeCount = 0; // n-1 edge required to form tree
   int i = 0;
   ll ans = 0;
   while(edgeCount < n-1 && i< input.size()){
        Edge curr = input[i]; // because input is sorted in the increasing order so we will get minimum wt
        int srcPar = find(parent,curr.src);
        int destPar = find(parent,curr.dest);
        if(srcPar != destPar){
            //include edge as this will not make cycle

            Union(parent,rank,srcPar,destPar);
            ans += curr.wt;
            edgeCount++;
        }
        i++;// doesnot matter you picked the last edge or not you have to go the next edge 
   }

   return ans;

}

int main(){
    int n,e;
    cin>>n>>e;
    vector<Edge> v(e);
    for(int i=0;i<e;i++){
        cin>>v[i].src>>v[i].dest>>v[i].wt;
    }
    cout<<kruskals(v,n,e);
}