// { Driver Code Starts
// Counts Palindromic Subsequence in a given String
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    /*You are required to complete below method */
    
    long long int  countPS(string str)
    {
       int n=str.length();
       long long int dp[n][n];
       const int mod = 1e9+7;
       for(int len=1;len<=n;len++){
           int i=0,j=len-1;
           while(i<n and j<n){
               if(i==j){
                   dp[i][j]=1;
               }
               else if(i+1==j){
                   if(str[i]==str[j]){
                       dp[i][j]=3;
                   }
                   else{
                       dp[i][j]=2;
                   }
               }
               else{
                   if(str[i]==str[j]){
                       dp[i][j]=(1+dp[i][j-1]%mod+dp[i+1][j]%mod)%mod;
                   }
                   else{
                       dp[i][j]=(mod+dp[i][j-1]%mod+dp[i+1][j]%mod-dp[i+1][j-1])%mod;
                   }
               }
               i++;
               j++;
           }
       }
       return dp[0][n-1]%mod;
    }
     
};

// { Driver Code Starts.
// Driver program
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin>>str;
        Solution ob;
        long long int ans = ob.countPS(str);
        cout<<ans<<endl;
    } 
}  // } Driver Code Ends