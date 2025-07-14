#include<iostream>
#include<vector>
#include<string>
using namespace std;

class solution{
public:

    bool DFS(int node,vector<int> &color,bool graph[101][101],int m,int n){
        for(int i=0;i<m;i++){
            bool isposs=1;
            for(int j=0;j<n;j++){
                if(graph[node][j]&&color[j]==i){
                    isposs=0;
                    break;
                }
            }

            if(isposs==0)
            continue;
            color[node]=i;
            for(int j=0;j<n;j++){
                if(graph[node][j]&&color[j]==-1){
                    if(!DFS(j,color,graph,m,n)){
                        isposs=0;
                        break;
                    }
                }
            }

            if(isposs==1){
                return 1;
            }
            color[node]=-1;
        }
        return 0;
    }

    bool graphColoring(bool graph[101][101],int m,int n){
        vector<int>color(n,-1);
        for(int i=0;i<n;i++){
            if(color[i]&&!DFS(i,color,graph,m,n)){
                return 0;
            }
            return 1;
        }
    }    
};

int main(){
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

