//LCS: printing one possible solution(basic case)
#include<iostream>
#include<vector>
#include<string>
using namespace std;
void printLCS(vector<vector<string>>& b,vector<char>& p,int i,int j){
    if(i==0||j==0){
        return;
    }
    if(b[i][j]=="DG"){
        printLCS(b,p,i-1,j-1);
        cout<<p[i-1];
    }
    else if(b[i][j]=="UP"){
        printLCS(b,p,i-1,j);
    }
    else{
        printLCS(b,p,i,j-1);
    }
}
int LCS(vector<char>& p,vector<char>& q){
    int m=p.size();
    int n=q.size();
    vector<vector<int>> c(m+1,vector<int> (n+1,0));
    vector<vector<string>> b(m+1,vector<string> (n+1,""));
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(p[i-1]==q[j-1]){
                c[i][j]=c[i-1][j-1]+1;
                b[i][j]="DG";
            }
            else if(c[i-1][j]>=c[i][j-1]){
                c[i][j]=c[i-1][j];
                b[i][j]="UP";
            }
            else{
                c[i][j]=c[i][j-1];
                b[i][j]="LF";
            }
        }
    }

    cout<<"LCS is: ";
    printLCS(b,p,m,n);
    cout<<endl;
    return c[m][n];
}
int main(){
    vector<char> arr1={'a', 'b', 'c', 'b', 'd', 'a', 'b'};
    vector<char> arr2={'b', 'd', 'c', 'a', 'b', 'a'};
    cout<<"length of LCS is: "<<LCS(arr1,arr2)<<endl;
}