#include<iostream>
#include<stack>
#include<vector>
using namespace std;
class solution{
public:

    void Topological(int node,vector<vector<int>>&adj,vector<bool> &visited,stack<int> &s){
        visited[node]=1;
        for(int j=0;j<adj[node].size();j++){
            if(!visited[adj[node][j]]){
                Topological(adj[node][j],adj,visited,s);
            }
        }
        s.push(node);
    }

    void dfs(int node,vector<vector<int>>&adj,vector<bool> &visited){
        visited[node]=1;
        //look at neighbours one by one
        for(int j=0;j<adj[node].size();j++){
            int neighbor=adj[node][j];
            if(!visited[neighbor]){
                dfs(neighbor,adj,visited);
            }
        }
    }

    int kosaraju(int v,vector<vector<int>>&adj){
        stack<int> s;
        vector<bool> visited(v,0);
        for(int i=0;i<v;i++){
            if(!visited[i]){
                Topological(i,adj,visited,s);
            }
            
        }
        //transpose
        vector<vector<int>> adj2(v);
        for(int i=0;i<v;i++){
            for(int j=0;j<adj[i].size();j++){
                int u=i;
                int v=adj[i][j];
                adj2[v].push_back(u);
            }
        }
        for(int i=0;i<v;i++){
            visited[i]=0;
        }
        int SCC=0;
        while(!s.empty()){
            int p=s.top();
            s.pop();
            if(!visited[p]){
                SCC++;
                dfs(p,adj2,visited);
            }
        }
        return SCC;
    }
    
};
int main() {
    int V = 5; // Number of vertices
    solution sol;

    // Creating the graph (as an adjacency list)
    vector<vector<int>> adj(V);

    // Example graph:
    // 0 → 1
    // 1 → 2
    // 2 → 0
    // 1 → 3
    // 3 → 4
    adj[0].push_back(1);
    adj[1].push_back(2);
    adj[2].push_back(0);
    adj[1].push_back(3);
    adj[3].push_back(4);

    int scc_count = sol.kosaraju(V, adj);
    cout << "Number of Strongly Connected Components (SCCs): " << scc_count << endl;

    return 0;
}
