// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int median(vector<vector<int>> &matrix, int row, int c){
        int l=INT_MAX,r=INT_MIN;
        for(int i=0;i<row;i++){
            l=min(matrix[i][0],l);
        }
        for(int i=0;i<row;i++){
            r=max(matrix[i][c-1],r);
        }
        int desired=(row*c)/2;
        while(l<=r){
            int mid=(l+r)/2,count=0;
            //cout<<mid<<" ";
            for(int i=0;i<row;i++){
                count+=(upper_bound(matrix[i].begin(),matrix[i].end(),mid)-matrix[i].begin());
            }
            if(count<=desired){
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        return l;
        
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        cout<<obj.median(matrix, r, c)<<endl;        
    }
    return 0;
}  // } Driver Code Ends