#include<iostream>
using namespace std;

int main(){
    int n=5;
    
    

    for(int line=1;line<=n;line++){
        for(int k=0;k<n-line;k++){
            cout<<" ";
        }
        for(int j=0;j<2*line-1;j++){
            cout<<(char)('a'+j);
        }
        cout<<"\n";
    }

    for(int line=n+1;line<2*n+1;line++){
        for(int k=0;k<line-n;k++){
            cout<<" ";
        }
        for(int j=0;j<2*(2*n-line)-1-;j++){
            cout<<(char)('a'+j);
        }
        cout<<"\n";
    }
    return 0;
}