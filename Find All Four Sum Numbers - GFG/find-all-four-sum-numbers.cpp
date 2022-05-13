// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &arr, int k) {
        vector<vector<int>> ans;
        sort(arr.begin(),arr.end());
        int n=arr.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int x=j+1,y=n-1;
                while(x<y){
                    int target=arr[i]+arr[j]+arr[x]+arr[y];
                    if(target==k){
                        ans.push_back({arr[i],arr[j],arr[x],arr[y]});
                        while(x+1<n and arr[x]==arr[x+1]){
                            x++;
                        }
                        x++;
                        while(y-1>=0 and arr[y]==arr[y-1]){
                            y--;
                        }
                        y--;
                        
                    }
                    else if(target>k){
                        y--;
                    }
                    else if(target<k){
                        x++;
                    }
                }
                while(j+1<n and arr[j+1]==arr[j]){
                  j++;
              }
            }
            while(i+1<n and arr[i+1]==arr[i]){
                i++;
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
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}  // } Driver Code Ends