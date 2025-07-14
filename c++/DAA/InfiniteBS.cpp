// #include<iostream>
// using namespace std;

// int binary_search(int arr[], int l,int r, int k){
// 	int mid=(l+r)/2;
// 	while(l<r){
// 		if(arr[mid]==k){
// 			cout<<"FOUND"<<endl;
// 			return mid;
// 		}
// 		else if(arr[mid]<k){
// 			mid=mid+1;
// 		}
// 		else{
// 			mid=mid-1;
// 		}
// 	}

// }

// int range(int arr[],int k){
// 	int l=0;
// 	int r=1;
// 	while(arr[r]<k){
// 		l=r;
// 		r=r*2;
		
// 	   if(arr[r]==k){
// 		 return r;
// 	   }
// 	}
// 	binary_search(arr,l,r,k);
	
// }


// int main(){
// 	int arr[]={3,5,7,9,10,90,100,130,140,160,170};	
// 	cout<<range(arr,130);
// 	return 0;	
// }
#include<iostream>
using namespace std;
int binarySearch(int arr[],int l,int r,int k){
    while(l<r){
        int mid=l+(r-l)/2;
        if(arr[mid]==k){
            return mid;
        }
        else if(arr[mid]<k){
            mid++;
        }
        else{
            mid--;
        }
    }
     
}
int find_range(int arr[],int k){
    int l=0;
    int r=1;
    while(arr[r]<k){
        l=r;
        r=r*2;
        if(arr[r]==k){
            return r;
        }
    }
    binarySearch(arr,l,r,k);
}
int main(){
    int arr[]={1,3,5,8,9,23,25,54,65,74,77,98};
    cout<<find_range(arr,54);
    return 0;
}