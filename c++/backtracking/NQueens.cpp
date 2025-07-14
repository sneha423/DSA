#include<iostream>
#include<vector>
#include<string>
using namespace std;
class solution{
public:

    bool isSafe(vector<string> &board,int row,int col,int n){
        for (int i = 0; i < row; i++) {
            if (board[i][col] == 'Q'){
                 return false;
            }
        }
        for(int i=row,j=col;i>=0&&j>=0;i--,j--){
            if(board[i][j]=='Q'){
                return false;
            }
        }
        for(int i=row,j=col;i>=0&&j<n;i--,j++){
            if(board[i][j]=='Q'){
                return false;
            }
        }
        return true;
    }

    void NQueen(vector<string> &board,int row,int n,vector<vector<string>> &ans){

        if(row==n){
            ans.push_back({board});
            return;
        }
        for(int j=0;j<n;j++){
            if(isSafe(board,row,j,n)){
                board[row][j]='Q';
                NQueen(board,row+1,n,ans);
                board[row][j]='-';
            }
        }
    }

    vector<vector<string>> solveNQueen(int n){
        vector<string> board(n,string(n,'-'));
        vector<vector<string>> ans;

        NQueen(board,0,n,ans);
        return ans;
    }

};
int main(){
    int n;
    cout<<"enter value of n"<<endl;
    cin>>n;
    solution s;
    vector<vector<string>> solutions = s.solveNQueen(n);

    cout << "Solutions:\n";
    for (const auto &board : solutions) {
        cout<<endl;
        for (const auto &row : board) {
            cout << row << endl;
        }
       
    

    cout<<"positions of queens:"<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(board[i][j]=='Q'){
                cout<<j+1;
                if(i!=(n-1)){
                    cout<<",";
                }
                break;
            }
        }
    }
    cout<<endl;
}
    return 0;
}