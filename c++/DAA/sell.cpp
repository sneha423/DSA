//BUY-SELL (DIVIDE & CONQUER)
#include<iostream>
using namespace std;

int maximum(int a ,int b,int c){
	if(a>b&&a>c)
		return a;
		
	if (b>c&&b>c)
		return b;
	
	else
		return c;
}

int cross_sum(int arr[],int n,int p,int r){
	int mid=(p+r)/2;
	
	int minval_left=INT8_MAX;
	for(int i=p;i<=mid;i++){
		if(arr[i]<minval_left){
			minval_left=arr[i];
		}		
	}
	cout<<"minval_left:"<<minval_left<<endl;
	
	int maxval_right=INT8_MIN;
	for(int i=mid+1;i<=r;i++){
		if(arr[i]>maxval_right){
			maxval_right=arr[i];
		}		
	}
	cout<<"maxval_right:"<<maxval_right<<endl;
	
	return (maxval_right-minval_left); //profit
	
}

int profit(int arr[],int n,int p,int r){
	int max;
	int maxprofit=0;
	for(int i=p;i<r;i++){
		if(arr[i]<arr[i+1]){
			max=arr[i+1]-arr[i];
			if(max>maxprofit){
				maxprofit=max;
			}
		}
	}	
	return maxprofit;
}

int max_sum(int arr[],int n,int p,int r){
	int mid=(p+r)/2;
	if(p==r)	
		return arr[p];
	
	int leftval=profit(arr,n,p,mid);
	cout<<"left:"<<leftval<<endl;
	int rightval=profit(arr,n,mid+1,r);
	cout<<"right:"<<rightval<<endl;
	int crossval=cross_sum(arr,n,0,n-1);
	cout<<"crossval:"<<crossval<<endl<<endl;
	
	return maximum(leftval,rightval,crossval);
}

int main(){
	int arr[]={9,4,2,1};                   //{1,8,7,2} ans=7, but 6 coming  ??
	int n=sizeof(arr)/sizeof(arr[0]);      //{5,4,6,2} ans=2  but left=0,right=0,cross=2
	int ans=max_sum(arr,n,0,n-1);
	cout<<"ans:"<<ans;
}
