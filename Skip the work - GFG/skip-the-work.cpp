// { Driver Code Starts
#include <iostream>
using namespace std;

 // } Driver Code Ends

class Solution
{
  public:
    int minAmount(int A[] , int N)
    {
        if(N==1) return A[0];
        if(N==2) return min(A[0],A[1]);
        for(int i=N-3;i>=0;i--){
            A[i]=A[i]+min(A[i+1],A[i+2]);
        }
        return min(A[0],A[1]);
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
        {
            int n;
            cin>>n;
            int arr[n];
            for(int i = 0;i<n;i++)
                cin>>arr[i];
            Solution ob;    
            cout<<ob.minAmount(arr,n)<<endl;    
        }
}  // } Driver Code Ends