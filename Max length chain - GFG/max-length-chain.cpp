// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct val{
	int first;
	int second;
};



int maxChainLen(struct val p[],int n);
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		val p[n];
		for(int i=0;i<n;i++)
		{
			cin>>p[i].first>>p[i].second;
		}
		
		cout<<maxChainLen(p,n)<<endl;
	}
	return 0;
}// } Driver Code Ends


/*
The structure to use is as follows
struct val{
	int first;
	int second;
};*/

/*You are required to complete this method*/
bool static mysort(struct val a,struct val b){
    return a.second<b.second;
}
int maxChainLen(struct val p[],int n)
{
    int dp[n];
    dp[0]=1;
    sort(p,p+n,mysort);
    for(int i=1;i<n;i++){
        dp[i]=1;
        for(int j=0;j<i;j++){
            if(p[i].first>p[j].second){
                dp[i]=max(dp[i],1+dp[j]);
            }
        }
    }
    return *max_element(dp,dp+n);
}