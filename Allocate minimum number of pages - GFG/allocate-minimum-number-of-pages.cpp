// { Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    bool ispossible(int A[],int mid,int n,int m){
        int c=0,pages=0;
        for(int i=0;i<n;i++){
            if(A[i]+pages>mid){
                c++;
                pages=A[i];
                if(pages>mid){
                    return false;
                }
            }
            else{
                pages=pages+A[i];
            }
        }
        if(c>=m){
            return false;
        }
            return true;
    }
    //Function to find minimum number of pages.
    int findPages(int A[], int N, int M) 
    {
        if(N<M) return -1;
        int sum=0;
        for(int i=0;i<N;i++) sum+=A[i];
        int l=0,r=sum,ans=0,ans1=-1;
        while(l<=r){
            int mid=(l+r)/2;
            //cout<<l<<" "<<r<<" ";
            if(ispossible(A,mid,N,M)){
                //cout<<mid<<endl;
                ans1=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans1;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}
  // } Driver Code Ends