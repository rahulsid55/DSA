// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
		

	public:
	int minOperations(string str1, string str2) 
	{ 
	    int n1=str1.length(),n2=str2.length();
	    int dp[n1+1][n2+1];
	    for(int i=0;i<=n1;i++){
	        for(int j=0;j<=n2;j++){
	            if(i==0 and j==0){
	                dp[i][j]=0;
	            }
	            else if(i==0){
	                dp[i][j]=1+dp[i][j-1];
	            }
	            else if(j==0){
	                dp[i][j]=1+dp[i-1][j];
	            }
	        }
	    }
	    for(int i=1;i<=n1;i++){
	        for(int j=1;j<=n2;j++){
	            if(str1[i-1]==str2[j-1]){
	                dp[i][j]=dp[i-1][j-1];
	            }
	            else{
	                dp[i][j]=1+min(dp[i-1][j],dp[i][j-1]);
	            }
	        }
	    }
	    for(int i=0;i<=n1;i++){
	        for(int j=0;j<=n2;j++){
	            //cout<<dp[i][j]<<" ";
	        }
	        //cout<<endl;
	    }
	    return dp[n1][n2];
	    
	} 
};

// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

	    Solution ob;
	    cout << ob.minOperations(s1, s2) << "\n";
	     
    }
    return 0;
}

  // } Driver Code Ends