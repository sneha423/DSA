#include<iostream>
#include<stack>
using namespace std;
int main(){
    string s;
    cout<<"enter string"<<endl;
    cin>>s;
    stack<char> st;
    bool ans=false;
    for(int i=0;i<s.size();i++){
        if(s[i]=='+'||s[i]=='*'||s[i]=='/'||s[i]=='-'||s[i]=='^'){
            st.push(s[i]);
        }
        else if(s[i]=='('){
            st.push(s[i]);
        }
        else if(s[i]==')'){
            if(st.top()=='('){
                ans=true;
            }
            while(st.top()!='('){
                st.pop();
            }
            st.pop();
        }
    }
    cout<<ans;
}