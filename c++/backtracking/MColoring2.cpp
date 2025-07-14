#include<iostream>
#include<vector>
#include<string>
using namespace std;

class solution{
public:

    bool find(int node,bool graph[101][101],int m,int n,vector<int> &color){
        if(node==n){
            return 1;
        }
        for(int i=0;i,m;i++){
            bool isPoss=1;
            for(int j=0;j<n;j++){
                if(graph[node][j]&&color[j]==i){
                    isPoss=0;
                    break;
                }
            }
            if(isPoss){
                color[node]=i;
                if(find(node+1,graph,m,n,color)){
                    return 1;
                }
                color[node]=-1;
            }
        }
    }

    bool graphColoring(bool graph[101][101],int m,int n){
        vector<int>color(n,-1);
        return find(0,graph,m,n,color);
    }
};int main(){
    int n = 4; // Number of nodes
    int m = 3; // Number of colors

    // Hardcoded adjacency matrix for a sample graph
    bool graph[101][101] = {false};
    graph[0][1] = true; graph[1][0] = true;
    graph[0][2] = true; graph[2][0] = true;
    graph[1][3] = true; graph[3][1] = true;
    graph[2][3] = true; graph[3][2] = true;

    solution s;
    if (s.graphColoring(graph, m, n)) {
        cout << "Graph can be colored with " << m << " colors.\n";
    } 
    else {
        cout << "Graph cannot be colored with " << m << " colors.\n";
    }

    return 0;
}