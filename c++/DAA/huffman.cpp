#include<iostream>
#include<unordered_map>
#include<queue>
#include<string>
using namespace std;

class node{
public:
char data;
int freq;
node* left,right;
node(char a,int f):data(a),freq(f),left(nullptr),right(nullptr) {}
};

bool compare(node* a,node* b){
    return a->freq>b->freq;
}
class coding{
public:
node* root;
unordered_map<char,string> code;

void genCode(node* a,string c){
    if(!node) return;

}
coding():root(nullptr){}
void buildTree(string& text){
    unordered_map<char,int> freq;
    for(cahr ch:text) freq[ch]++;
}
};
int main(){
    string code="hello this is Sneha";
}