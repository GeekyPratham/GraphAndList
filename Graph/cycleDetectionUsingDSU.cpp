#include <iostream>

#include <vector>

using namespace std;

int find(int x,vector<int> &parent) {
    if(parent[x]==x) return x;
    return parent[x]= find(parent[x],parent);
}

bool Union(int a,int b,vector<int> &parent,vector<int> &rank){
    a = find(a,parent);
    b = find(b,parent);
    if(a==b) return true;
    if(rank[a] <= rank[b]){
        parent[a] = b;
        rank[b]++;
    }
    else{
        parent[b] = a;
        rank[a]++;
    }
    return false;
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
        int x,y;
        cin>>x>>y;
        bool ans = Union(x,y,parent,rank);
        if(ans==true) {
            cout<<"cycle detected"<<endl;
            break;
        }
        
    }

}