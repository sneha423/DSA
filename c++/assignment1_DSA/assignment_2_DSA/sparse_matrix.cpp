#include<iostream>
using namespace std;

int sparseMatrix(int arr[]){
    int size=0;
    for(int i=0;i<4;i++){
        for(int j=0;j<5;j++){
            if(arr[i][j]!=0){
                size++;
            }
        }
    }
return size;
}

void compactMatrix(int arr[],int size){
    int new_arr[size+1][3];
    int k=1;
    new_arr[0][0]=4;
    new_arr[0][1]=5;
    new_arr[0][2]=size;

    for(int i=0;i<4;i++){
        for(int j=0;j<5;j++){
            if (arr[i][j]!=0){
                new_arr[k][0]=i;
                new_arr[k][1]=j;
                new_arr[k][2]=arr[i][j];
                k++;
            }
        }
    }
    for(int i=0;i<size+1;i++){
        for(int j=0;j<3;j++){
            cout<<new_arr[i][j];
            cout<<endl;
        }
    }
    
}

// void display(int arr[],int size){
//     for(int i=0;i<size+1;i++){
//         for(int j=0;j<3;j++){
//             cout<<new_arr[i][j];
//             cout<<endl;
//         }
//     }
// }


int main(){
int arr[4][5]=
{
    {0,4,0,0,8},
    {2,0,0,9,0},
    {5,0,0,7,1},
    {6,0,1,0,0}
};
int l=sparseMatrix(arr);
compactMatrix(arr,l);
// display(final_arr,l);

}