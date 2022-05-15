// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<vector<int>> rotateMatrix(int m, int n, vector<vector<int>> Mat) {
        int left =0,right=m-1,top=n-1,bottom=0,x=0,temp,a,b;
        while(left<right and top>bottom){
                temp=Mat[left+1][bottom];
                for(int i=bottom;i<=top;i++){
                        int x=Mat[left][i];
                        Mat[left][i]=temp;
                        temp=x;
                    }
                left++;
            
                for(int i=left;i<=right;i++){
                        //cout<<temp<<"&";
                        int x=Mat[i][top];
                        Mat[i][top]=temp;
                        temp=x;
                    }
                top--;
            
        
                for(int i=top;i>=bottom;i--){
                        int x=Mat[right][i];
                        Mat[right][i]=temp;
                        temp=x;
                    }
                right--;
               
            

                 
                for(int i=right;i>=left;i--){
                    
                        int x=Mat[i][bottom];
                        Mat[i][bottom]=temp;
                        temp=x;
                }
                //Mat[a][b]=temp;
                bottom++;
           
        }
        return Mat;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, i, j;
        cin >> N >> M;
        vector<vector<int>> Mat(N, vector<int>(M));
        for (i = 0; i < N; i++)
            for (j = 0; j < M; j++) cin >> Mat[i][j];
        Solution ob;
        vector<vector<int>> ans = ob.rotateMatrix(N, M, Mat);
        for (i = 0; i < N; i++) {
            for (j = 0; j < M; j++) cout << ans[i][j] << " ";
            cout << "\n";
        }
    }
}  // } Driver Code Ends