// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    int eggDrop(int n, int k) 
    {
        int dp[n+1][k+1],c;
        for(int i=0;i<=k;i++){
            dp[1][i]=i;
        }
        for(int i=2;i<=n;i++){
            dp[i][0]=0;
            for(int j=1;j<=k;j++){
                dp[i][j]=INT_MAX;
                for(int floor=1;floor<=j;floor++){
                    c=1+max(dp[i-1][floor-1],dp[i][j-floor]);
                    dp[i][j]=min(dp[i][j],c);
                }
            }
        }
        return dp[n][k];
    }
};

// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking eggs and floors count
        int n, k;
        cin>>n>>k;
        Solution ob;
        //calling function eggDrop()
        cout<<ob.eggDrop(n, k)<<endl;
    }
    return 0;
}
  // } Driver Code Ends