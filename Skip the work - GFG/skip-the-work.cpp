// { Driver Code Starts
#include <iostream>
using namespace std;

 // } Driver Code Ends

class Solution
{
  public:
    int minAmount(int A[] , int N)
    {
        int sum=0,dp[2][N];
        for(int i=0;i<N;i++){
            sum+=A[i];
            if(i==0){
                dp[0][i]=0;
                dp[1][i]=A[i];
            }
            else{
                dp[0][i]=max(dp[0][i-1],dp[1][i-1]);
                dp[1][i]=A[i]+dp[0][i-1];
            }
        }
        return sum-max(dp[0][N-1],dp[1][N-1]);
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