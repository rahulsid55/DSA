class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        for(int i=1;i<n;i++){
            for(int j=0;j<triangle[i].size();j++){
                int k=INT_MAX;
                if(j>=1){
                    k=triangle[i-1][j-1];
                }
                if(j<i)
                k=min(k,triangle[i-1][j]);
                triangle[i][j]=k+triangle[i][j];
                //cout<<triangle[i][j]<<" ";
        }
            //cout<<endl;
    }
    int ans=INT_MAX;
    for(int i=0;i<triangle[n-1].size();i++){
        ans=min(ans,triangle[n-1][i]);
    }
        return ans;
    }
};