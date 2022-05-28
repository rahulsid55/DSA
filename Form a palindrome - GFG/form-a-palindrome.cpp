// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int findMinInsertions(string S){
        int n=S.length(),ans=1;
        string S1=S;
        reverse(S1.begin(),S1.end());
        int dp[n+1][n+1];
        dp[0][0]=0;
        for(int i=1;i<=n;i++){
            dp[0][i]=dp[0][i-1];
            dp[i][0]=dp[i-1][0];
        }
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(S[i-1]==S1[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return n-dp[n][n];
        
    }
};

// { Driver Code Starts.



int main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        Solution ob;
        cout<<ob.findMinInsertions(S)<<endl;
    }
    return 0;
}
  // } Driver Code Ends