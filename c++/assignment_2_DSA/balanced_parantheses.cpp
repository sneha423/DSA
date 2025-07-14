#include<iostream>
#include<stack>
#include<string>
using namespace std;

bool arePair(char opening,char closing){
if (opening=='('&& closing==')') return true;
if (opening=='{'&& closing=='}') return true;
if (opening=='['&& closing==']') return true;
return false;
}

bool balancedExpr(string expr){
    stack<char> s;
    for(int i=0;i<expr.length();i++){
        if(expr[i]=='('||expr[i]=='{'||expr[i]=='['){
            s.push(expr[i]);
        }
        else if(expr[i]==')'||expr[i]=='}'||expr[i]==']'){
            if(s.empty()|| !arePair(s.top(),expr[i])){
                return false;
            }
            else{
                s.pop();
            }
        }
    }
    return s.empty() ?true:false;
}

int main(){
    string expr="({[6)])";
    if(balancedExpr(expr)){
        cout<<"balanced";
    }
    else{
        cout<<"not balanced";
    }
}
