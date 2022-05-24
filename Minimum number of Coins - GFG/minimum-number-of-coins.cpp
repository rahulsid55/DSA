// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> minPartition(int N)
    {
        int dp[N+1];
        dp[0]=0;
        int coins[10]={1,2,5,10,20,50,100,200,500,2000};
        for(int i=1;i<=N;i++){
            dp[i]=INT_MAX;
            for(int j=0;j<10;j++){
                if(coins[j]<=i){
                    dp[i]=min(dp[i],1+dp[i-coins[j]]);
                }
            }
        }
        int x=dp[N],t=N;
        vector<int> ans;
        while(t){
        for(int i=0;i<10;i++){
            if(t-coins[i]>=0 and dp[t-coins[i]]==x-1){
                ans.push_back(coins[i]);
                t=t-coins[i];
                x--;
            }
         }
        }
        sort(ans.begin(),ans.end(),greater<int>());
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        vector<int> numbers = ob.minPartition(N);
        for(auto u: numbers)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}  // } Driver Code Ends