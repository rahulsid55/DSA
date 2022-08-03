class Solution {
public:
    map<pair<int,int>, pair<int,int>> dp;
    pair<int,int> solve(vector<int> arr,int l,int r){
        if(l==r){
            return {0,arr[l]};
        }
        if(dp.count({l,r})) return dp[{l,r}];
        int prod_sum=INT_MAX;
        int max_leaf=INT_MIN;
        for(int k=l;k<r;k++){
            pair<int,int> left=solve(arr,l,k);
            pair<int,int> right=solve(arr,k+1,r);
            prod_sum=min(prod_sum,left.first+right.first+(left.second)*(right.second));
            max_leaf=max(left.second,right.second);
        }
        return dp[{l,r}]={prod_sum,max_leaf};
    }
    int mctFromLeafValues(vector<int>& arr) {
        int n=arr.size();
        return solve(arr,0,n-1).first;
        
    }
};