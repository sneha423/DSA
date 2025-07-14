#include<iostream>
using namespace std;

class tracker{
int id;
int step_count;
int stair_count;
static int objects;
public:
tracker(int x){
    cout<<"enter id:"<<endl;
    cin>>x;
     id=x;
    step_count=0;
    stair_count=0;
    objects++;
}
// void getInfo(){

   
//     cout<<"enter stair steps:"<<endl;
//     cin>>stair_count;
//     stair_count;
// }
void incCount(int n);
static void countObjects(){
    cout<<objects;
}
friend void convertStep(tracker &h);
void displayCount(){
    cout<<"person id\t"<<id<<"step_count\t"<<step_count<<endl;
}
};
int tracker::objects=0;

void tracker::incCount(int n){
    step_count=step_count+n;
    stair_count=stair_count+n;
}
void convertStep(tracker &h){
    h.step_count=2*h.stair_count;
}

int main(){
    tracker t[5];
    for(int i=0;i<5;i++){
        tracker::countObjects();
        cout<<"enter info of "<<i+1<<" person"<<endl;
        
        // t[i].getInfo();
        convertStep(t[i]);
        t[i].displayCount();
    }

    return 0;
}