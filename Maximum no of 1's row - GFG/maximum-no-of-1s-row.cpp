// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
        int maxOnes (vector <vector <int>> &Mat, int n, int m)
        {
            int maxi=0,one=0;
            for(int i=0;i<n;i++){
                int l=0,r=m-1;
                while(l<=r){
                int mid=(l+r)/2;
                //cout<<mid<<endl;
                if(Mat[i][mid]==0){
                    l=mid+1;
                }
                else{
                    r=mid-1;
                 }
                  //cout<<l<<" "<<r<<" ";
                }
                if(one<(m-r)){
                    one=m-r;
                    maxi=i;
                }
                
                
            }
            return maxi;
        }
};

// { Driver Code Starts.

int main(){
    int t; cin >> t;
    while (t--){
        int n, m; cin >> n >> m;
        vector <vector <int>> arr (n, vector <int> (m));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> arr[i][j];
        Solution ob;        
        cout << ob.maxOnes(arr, n, m) << endl;
    }
}  // } Driver Code Ends