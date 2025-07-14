#include<iostream>
#include<list>
#include<unordered_map>
using namespace std;
template<typename T>
class graph{

    public:
    unordered_map<T,list<T>> adj;
    void addEgde(T u,T v,bool dir){
        adj[u].push_back(v);
        if(dir==0){
            adj[v].push_back(u);
        }
        
    }

    void print(){
        for(auto i:adj){
            cout<<i.first<<"->";
            for(auto j:i.second){
                cout<<j<<",";
            }
            cout<<endl;
        }
    }
};
int main(){
    int n;
    cout<<"enter no of vertices";
    cin>>n;

    int e;
    cout<<"enter no of edges";
    cin>>e;
    graph<int> g;
    for(int i=0;i<e;i++){
        int u,v;
        cin>> u >> v;
        g.addEgde(u,v,0);
        
    }
    g.print();
}