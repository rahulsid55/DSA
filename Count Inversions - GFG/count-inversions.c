// { Driver Code Starts
//Initial Template for C

#include <stdio.h>
#include <stdlib.h>


 // } Driver Code Ends
//User function Template for C


// arr[]: Input Array
// N : Size of the Array arr[]
// Function to count inversions in the array.
long long int merge(long long arr[],int l,int m,int r){
    long long int temp[r-l+1];
    long long int i=l,j=m+1,k=0,x=0;
    while(i<=m && j<=r){
        if(arr[i]>arr[j]){
            x+=m-i+1;
            temp[k++]=arr[j++];
        }
        else{
            temp[k++]=arr[i++];
        }
    }
    while(i<=m){ 
        temp[k++]=arr[i++];
    }
    while(j<=r){
         temp[k++]=arr[j++];
    }
    for(int k=l;k<=r;k++){
        arr[k]=temp[k-l];
    }
    
    return x;
}
long long int inversion(long long arr[],long long l,long long r){
    long long inv=0;
    if(l < r){
        long long int mid=(l+r)/2;
        inv=inversion(arr,l,mid);
        inv+=inversion(arr,mid+1,r);
        inv+=merge(arr,l,mid,r);
    }
    return inv;
    
}
long long int inversionCount(long long arr[], long long N)
{
        return inversion(arr,0,N-1);
    
}



// { Driver Code Starts.

int main() {
    
    long long T;
    scanf("%ld", &T);
    
    while(T--){
        long long N;
        scanf("%ld", &N);
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            scanf("%ld", &A[i]);
        }
        
        printf("%ld\n", inversionCount(A,N) );
    }
    
    return 0;
}
  // } Driver Code Ends