// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

  public:
		int minDifference(int arr[], int n)  { 
	    int sum=0;
	    for(int i=0;i<n;i++) sum+=arr[i];
	    bool dp[n+1][sum+1];
	    for(int i=0;i<=n;i++){
	        for(int j=0;j<=sum;j++){
	            dp[i][j]=false;
	        }
	    }
	    dp[0][0]=true;
	    for(int i=1;i<=n;i++){
	        for(int j=1;j<=sum;j++){
	            if(arr[i-1]<=j){
	                dp[i][j]=dp[i-1][j] or dp[i-1][j-arr[i-1]];	            
	                
	            }
	            else{
	                dp[i][j]=dp[i-1][j];
	            }
	        }
	        
	    }
	    int ans=INT_MAX;
	        for(int j=1;j<=sum;j++){
	          if(dp[n][j]==true){
	              //cout<<j<<" ";
	            ans=min(ans,abs((sum-2*j)));
	        }
	  }
	    
	    return ans;
	} 
};


// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends