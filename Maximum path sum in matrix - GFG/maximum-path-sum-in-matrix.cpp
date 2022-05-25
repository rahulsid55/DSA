// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maximumPath(int n, vector<vector<int>> Matrix)
    {
        vector<vector<int>> dp(n,vector<int>(n,0));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==0) {
                    dp[i][j]=Matrix[i][j];
                }
                else{
                    
                    dp[i][j]=Matrix[i][j];
                    int maxi=0;
                    if(j>0){
                        maxi=max(dp[i-1][j-1],maxi);
                    }
                    if(j<n-1){
                        maxi=max(dp[i-1][j+1],maxi);
                    }
                       maxi=max(maxi,dp[i-1][j]);
                     dp[i][j]=dp[i][j]+maxi;
                }
            }
        }
        int x=0;
        for(int i=0;i<n;i++){
            x=max(x,dp[n-1][i]);
        }
        return x;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}  // } Driver Code Ends