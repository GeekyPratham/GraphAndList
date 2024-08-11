#include <iostream>
#include <vector>
using namespace std;

int find(int x,vector<int> &parent) {
    if(parent[x]==x) return x;
    return parent[x]= find(parent[x],parent);
}

void Union(int a,int b,vector<int> &parent,vector<int> &rank,vector<int> &size,vector<int>& minimal,vector<int> &maximal){
    a = find(a,parent);
    b = find(b,parent);

    if(a==b) return; // both  a and b are in same set

    if(rank[a] <= rank[b]){
        parent[a] = b;
        
        rank[b]++;
        size[b]=size[b]+size[a];
        maximal[b]=max(maximal[a],maximal[b]);
        minimal[b]=min(minimal[a],minimal[b]);
    }
    else{
        parent[b] = a;
        
        rank[a]++;
        size[a]=size[b]+size[a];
        maximal[a]=max(maximal[a],maximal[b]);
        minimal[a]=min(minimal[a],minimal[b]);
    }
}
int main(){
    // m is no of operations

    int m,n;
    cin>>n>>m;
    vector<int> parent(n+1);
    vector<int> rank(n+1,1);
    vector<int> size(n+1,1);
    vector<int> minimal(n+1);
    vector<int> maximal(n+1);
    for(int i=0;i<=n;i++){
        parent[i]=maximal[i]=minimal[i]=i;
    }

    while(m--){
        string str;
        cin>>str;
        if(str=="union"){
            int x,y;
            cin>>x>>y;
            Union(x,y,parent,rank,size,minimal,maximal);
        }
        else{
            int x;
            cin>>x;
             x = find(x,parent);
            cout<<x<<" "<<minimal[x]<<" "<<maximal[x]<<" "<<size[x]<<endl;
        }
    }

}
