#include<iostream>
#include<stack>
#include<vector>
using namespace std;
class solution{
public:

    DFS(int node,vector<int> adj[],vector<bool> visited,stack<int> &s){
        visited[node]=1;
        //look at neighbours one by one
        for(int j;j<adj[node].size();j++){
            int neighbor=adj[node][j];
            if(!visited[neighbor]){
                DFS(neighbor,adj,visited,s);

            }
        }
        s.push(node);
    }

    vector<int> Sort(int v,vector<int> adj[]){
        //DFS 
        vector<bool> visited(v,0);
        stack<int> s;
        for(int i=0;i<v;i++){
            if(!visited[i]){
                DFS(i,adj,visited,s);
            }
        }
        vector<int> ans;
        while (!s.empty())
        {
            ans.push_back(s.top());
            s.pop();
        }
        return ans; 
    }
};
int main(){
    int v = 6; // number of vertices
    vector<int> adj[6];

    // Sample Directed Acyclic Graph (DAG)
    adj[5].push_back(2);
    adj[5].push_back(0);
    adj[4].push_back(0);
    adj[4].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(1);

    solution sol;
    vector<int> result = sol.Sort(v, adj);

    cout << "Topological Sort using DFS: ";
    for (int node : result) {
        cout << node << " ";
    }
    cout << endl;
}