// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int maxBinTreeGCD(vector<vector<int>> arr, int N) {
        vector<int> v[100001];
        int maxi=0;
        for(int i=0;i<arr.size();i++){
            v[arr[i][0]].push_back(arr[i][1]);
        }
        for(auto x: v){
            for(int i=0;i<x.size();i++){
                for(int j=i+1;j<x.size();j++){
                    //cout<<x[i]<<" "<<x[j]<<endl;
                    maxi=max(maxi,__gcd(x[i],x[j]));
                }
            }
        }
        return maxi;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,u,v;
        cin>>N;
        
        vector<vector<int>> arr;
        
        for(int i=0; i<N-1; i++)
        {
            cin>>u>>v;
            vector<int> edge;
            edge.push_back(u);
            edge.push_back(v);
            arr.push_back(edge);
        }

        Solution ob;
        cout << ob.maxBinTreeGCD(arr,N) << endl;
    }
    return 0;
}  // } Driver Code Ends