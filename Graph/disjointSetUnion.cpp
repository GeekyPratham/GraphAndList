#include <iostream>

#include <vector>

using namespace std;

int find(int x,vector<int> &parent) {
    if(parent[x]==x) return x;
    return parent[x]= find(parent[x],parent);
}

void Union(int a,int b,vector<int> &parent,vector<int> &rank){
    a = find(a,parent);
    b = find(b,parent);
    if(rank[a] <= rank[b]){
        parent[a] = b;
        rank[b]++;
    }
    else{
        parent[b] = a;
        rank[a]++;
    }
}
int main(){
    // m is no of operations

    int m,n;
    cin>>m>>n;
    vector<int> parent(n+1);
    vector<int> rank(n+1,1);
    for(int i=0;i<=n;i++){
        parent[i]=i;
    }

    while(m--){
        string str;
        cin>>str;
        if(str=="union"){
            int x,y;
            cin>>x>>y;
            Union(x,y,parent,rank);
        }
        else{
            int x;
            cin>>x;
            cout<<find(x,parent)<<endl;
        }
    }

}