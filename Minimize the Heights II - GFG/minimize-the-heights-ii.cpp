// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int getMinDiff(int arr[], int n, int k) {
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++)
        {
            v.push_back({arr[i]+k,i});
            if(arr[i]-k>=0)
            {
                v.push_back({arr[i]-k,i});
            }
        }
        sort(v.begin(),v.end());
        int visited[n];
        memset(visited,0,sizeof(visited));
        int c=0,left=0,right=0;
        while(c<n and right<v.size())
        {
            if(visited[v[right].second]==0)
            {
                c+=1;
            }
            visited[v[right].second]+=1;
            right++;
        }
        int ans=v[right-1].first-v[left].first;
        while(right<v.size())
        {
            if(visited[v[left].second]==1)
            {
                c--;
            }
            visited[v[left].second]-=1;
            left++;
            while(c<n and right<v.size())
           {
            if(visited[v[right].second]==0)
            {
                c+=1;
            }
            visited[v[right].second]+=1;
            right++;
           }
           if(c==n)
           {
               ans=min(ans,(v[right-1].first-v[left].first));
           }
           else
           {
               break;
           }
    }
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> k;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getMinDiff(arr, n, k);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends