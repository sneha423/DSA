#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;
void printwithBracks(vector<vector<int>>& s,int i,int j){
    if(i==j){
        cout<<"A"<<i;
    }
    else{
        cout<<"(";
        printwithBracks(s,i,s[i][j]);
        printwithBracks(s,s[i][j]+1,j);
        cout<<")";
    }
}
int MCM(vector<int> &p){
    int n=p.size();
    vector<vector<int>> m(n,vector<int>(n,0));
    vector<vector<int>> s(n,vector<int>(n,0));

    for(int i=1;i<n;i++){
        m[i][i]=0;
    }
    for(int l=2;l<n;l++){
        for(int i=1;i<n-l+1;i++){
            int j=i+l-1;
            m[i][j]=INT_MAX;
            for(int k=i;k<=j-1;k++){
                int q=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
                if(q<m[i][j]){
                    m[i][j]=q;
                    s[i][j]=k;
                }
            }
        }
    }
    cout<<"solution: "<<endl;
    printwithBracks(s,1,n-1);
    cout<<endl;
    return m[1][n-1];
}

int main(){
    vector<int> arr={5,4,6,2,7};
    cout<<"min no of multiplications: "<<MCM(arr)<<endl;
    return 0;
} 