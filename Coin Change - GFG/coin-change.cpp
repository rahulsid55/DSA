// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    long long int count(int S[], int m, int n) {

            long dp[n+1];
            memset(dp,0,sizeof(dp));
       dp[0]=1;
       
       for(int i=0;i<m;i++){//Iterate to each coin 
           for(int j=S[i];j<=n;j++){// fill or dp for each value
               dp[j]+=dp[j-S[i]];
           }
       }
       return dp[n];
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int arr[m];
        for (int i = 0; i < m; i++) cin >> arr[i];
        Solution ob;
        cout << ob.count(arr, m, n) << endl;
    }

    return 0;
}  // } Driver Code Ends