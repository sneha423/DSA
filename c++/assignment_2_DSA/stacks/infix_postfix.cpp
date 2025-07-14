#include<iostream>
#include<stack>
#include<string>
using namespace std;

int precedence(char c){
    if(c=='^') return 3;
    if(c=='/'||c=='*'||c=='%') return 2;
    if(c=='+'||c=='-') return 1;
    else return -1;

}

string infixToPostfix(string s){
    stack<char> st;
    string result;
    st.push('(');
    s+=')';

    for(int i=0;i<s.length();i++){
        char c=s[i];
        if((c>='a'&&c<='z')||(c>='A'&&c<='Z')||(c>='0'&&c<='9')){
            result+=c;
        }
        else if(c=='('){
            st.push(c);
        }
        else if(c==')'){
            while(st.top()!='('){
                result+=st.top();
                st.pop();
            }
            st.pop();
        }
        else{
            if(!st.empty() && precedence(c)<=precedence(st.top())){
                result+=st.top();
                st.pop();
            }
            st.push(c);
        }
    }
    return result;
}


int main(){
    string exp="A+B-(C^D/(F+A))*E";
    string postfix=infixToPostfix(exp);
    cout<<postfix<<endl;
    
}