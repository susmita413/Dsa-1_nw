#include<bits/stdc++.h>
using namespace std;

void merge(int A[],int l, int mid, int h){
    int temp[200];
    int i = l ;
    int j = mid+1 ;
    int k =l ;
    while(i<=mid && j<=h){
        if(A[i] <= A[j]){
            temp[k] = A[i];
            i++ ;
            k++ ;
        }
        else{
            temp[k] = A[j];
            j++ ;
            k++ ;
        }
    }
    if(i>mid){
        while(j<=h){
            temp[k] = A[j];
            j++ ;
            k++ ;
        }
    }
    else{
        while(i<=mid){
            temp[k]= A[i] ;
            i++ ;
            k++ ;
        }
    }
    for(k=l ; k<=h ;k++){
        A[k] = temp[k];
    }
}


void DivideNConqure(int A[],int low,int high){
    if(low<high){
        int mid = (low+high)/2 ;
        DivideNConqure(A,low,mid);
        DivideNConqure(A,mid+1 , high);
        merge(A,low,mid,high);
    }
}


int main(){
    int arr[] = {9,15,32,7,2,-3,89,-50,7};
    int size = sizeof(arr)/sizeof(arr[0]);
    for(int i=0; i<size; i++){
        cout<< arr[i]<< " " ;
    }
    DivideNConqure(arr,0,size-1);
    cout<< "\nAfter sorting : " ;

    for(int i=0; i<size; i++){
        cout<< arr[i]<< " " ;
    }
}
