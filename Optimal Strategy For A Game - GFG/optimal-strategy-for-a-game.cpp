// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

//Function to find the maximum possible amount of money we can win.
class Solution{
    public:
    long long solution(vector<vector<long long>> &dp,int arr[],int i,int j){
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int x=arr[i]+min({solution(dp,arr,i+2,j),solution(dp,arr,i+1,j-1)});
        int y=arr[j]+min({solution(dp,arr,i,j-2),solution(dp,arr,i+1,j-1)});
        return dp[i][j]=max(x,y);
        
    }
    long long maximumAmount(int arr[], int n){
        vector<vector<long long>> dp(n,vector<long long> (n,-1));
        return solution(dp,arr,0,n-1);
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
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution ob;
		cout<< ob.maximumAmount(a,n)<<endl;
	}
	return 0;
}  // } Driver Code Ends