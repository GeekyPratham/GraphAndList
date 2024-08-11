#include <iostream>
#include <list>
#include <vector>

using namespace std;

void print_list(list<int> &l1){
    // for(auto it : l1){
    //     cout<<it<<" ";
    // }
    for(list<int>:: iterator it = l1.begin();it != l1.end();++it){
        cout<<*it<<" ";
    }
    cout<<endl;
}
int main(){
    list<int> l1={1,2,3,5};
    cout<<l1.front()<<endl;
    cout<<l1.back()<<endl;
    print_list(l1);
    cout<<l1.size()<<endl;
    list<int> l2=l1;
    cout<<l2.size()<<endl;
    print_list(l2);

    cout<<*l1.begin()<<","<<*l1.rbegin()<<endl;
    
    // vector<int> v={1,2,3,4};
    // for(int i=0;i<v.size();i++){
    //     cout<<v[i]<<" ";
    // }
    // cout<<endl;
    // v.insert(v.begin()+2,100);
    // for(int i=0;i<v.size();i++){
    //     cout<<v[i]<<" ";
    // }
    // cout<<endl;

    /* but insert in one time complexity not happen in list we have to do
    it through iteration by reaching that point and then insert 
    */
    print_list(l1);

    list<int> :: iterator it = l1.begin();
    while(*it != 3 && it!=l1.end()) it++;
    l1.insert(it,100);
    print_list(l1);

    l1.erase(it);
    print_list(l1);

    l1.remove(2);
    print_list(l1);

    l1.clear();
    print_list(l1);

    print_list(l2);

    l1.push_back(100);
    l1.push_back(20);
    print_list(l1);

}