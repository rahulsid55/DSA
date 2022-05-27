// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    bool isInterleave(string A, string B, string C) 
    {
        int n1=A.length(),n2=B.length();
        int dp[n1+1][n2+1];
        dp[0][0]=true;
        for(int i=1;i<=n2;i++){
            if(C[i-1]==B[i-1]){
                dp[0][i]=dp[0][i-1];
            }
        }
        for(int i=1;i<=n1;i++){
            if(C[i-1]==A[i-1]){
                dp[i][0]=dp[i-1][0];
            }
        }
        for(int i=1;i<=n1;i++){
            for(int j=1;j<=n2;j++){
                dp[i][j]=false;
                if(C[i+j-1]==A[i-1]){
                    dp[i][j]=dp[i][j] || dp[i-1][j];
                }
                if(C[i+j-1]==B[j-1]){
                    dp[i][j]=dp[i][j] || dp[i][j-1];
                }
            }
        }
        return dp[n1][n2];
    }

};

// { Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
		string a,b,c;
		cin>>a;
		cin>>b;
		cin>>c;
		Solution obj;
		cout<<obj.isInterleave(a,b,c)<<endl;
	}
	// your code goes here
	return 0;
}  // } Driver Code Ends