// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    void dfs(vector<vector<int>> &m,int i,int j,int n,vector<char> ds,vector<string> &ans){
        if(i==n-1 and j==n-1){
            string s="";
            for(auto x: ds){
                s+=x;
            }
            ans.push_back(s);
        }
        int h[4]={0,0,1,-1};
        int v[4]={1,-1,0,0};
        for(int k=0;k<4;k++){
            int X=i+h[k];
            int Y=j+v[k];
            if(X>=0 and Y>=0 and X<=n-1 and Y<=n-1 and m[X][Y]==1)
            {
                if(X>i){
                    ds.push_back('D');
                }
                else if(X<i)
                {
                    ds.push_back('U');
                }
                else if(Y<j)
                {
                    ds.push_back('L');
                }
                else if(Y>j)
                {
                    ds.push_back('R');
                }
                m[X][Y]=0;
                dfs(m,X,Y,n,ds,ans);
                m[X][Y]=1;
                ds.pop_back();
            }
        }
        
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<vector<int>> vis(n,vector<int>(0,n));
        vector<char> ds;
        vector<string> ans;
        if(m[0][0]==0) return ans;
        m[0][0]=0;
        dfs(m,0,0,n,ds,ans);
        return ans;
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends
