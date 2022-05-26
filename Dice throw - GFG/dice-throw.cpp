// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    long long noOfWays(int M , int N , int X) {
        long long dp[N+1][X+1];
        memset(dp,0,sizeof(dp));
        dp[0][0]=1;
        for(int i=1;i<=N;i++){
            for(int j=1;j<=X;j++){
                for(int k=1;k<=M;k++){
                    if(k<=j){
                        dp[i][j]+=dp[i-1][j-k];
                    }
                }
            }
        }
        return dp[N][X];
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int M,N,X;
        
        cin>>M>>N>>X;

        Solution ob;
        cout << ob.noOfWays(M,N,X) << endl;
    }
    return 0;
}  // } Driver Code Ends