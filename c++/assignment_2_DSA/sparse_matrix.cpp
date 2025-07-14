#include<iostream>
using namespace std;


int sparseMatrix(int arr[4][5],int m,int n){
    int size=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(arr[i][j]!=0){
                size++;
            }
        }
    }
return size;
}

int compactMatrix(int arr[4][5],int m,int n,int size){
    int new_arr[size+1][3];
    int k=1;
    new_arr[0][0]=4;
    new_arr[0][1]=5;
    new_arr[0][2]=size;

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
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
            cout<<new_arr[i][j]<<" ";
            
        }
        cout<<endl;
    }
    
}
//  int add(int arr1[l+1][3],int arr2[l+1][3],int size){
//     int add_arr[size+1][3]
//     for(int i=0;i<size+1;i++){
//         for(int j=0;j<3;j++){

//         }
//     }
//  }
void transpose(int arr[4][5],int size){
    int Tarr[size+1][3];
    int k=1;
    Tarr[0][0]=5;
    Tarr[0][1]=4;
    Tarr[0][2]=size;
    
    for(int i=0;i<5;i++){
        for (int j=1;j<=4;j++){
            if(Tarr[j][1]==i){
            Tarr[k][0]=j;
            Tarr[k][1]=i;
            Tarr[k][2]=arr[i][j];
            k++;
            }  
        }
    }
     for(int i=0;i<size+1;i++){
        for(int j=0;j<3;j++){
            cout<<Tarr[i][j]<<" ";
            
        }
        cout<<endl;
    }
}



int main(){
int arr1[4][5]=
{
    {0,4,0,0,8},
    {2,0,0,9,0},
    {5,0,0,7,1},
    {6,0,1,0,0}
};
int arr2[4][5]=
{
    {0,3,0,0,8},
    {2,0,7,9,0},
    {5,0,0,0,9},
    {6,4,1,0,0}
};
int l=sparseMatrix(arr1,4,5);
int final_matrix1=compactMatrix(arr1,4,5,l);
cout<<endl;
int final_matrix2=compactMatrix(arr2,4,5,l);
transpose(final_matrix1,l);

}