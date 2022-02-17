class Solution {
    void solve(vector<int>& candidates, int target,int x,vector<int> &ds,vector<vector<int>> &ans)
    {
       if(x==candidates.size())
       {
           if(target==0)
           {
               ans.push_back(ds);
           }
           return ;
       }
        
        if(candidates[x]<=target)
        {
            ds.push_back(candidates[x]);
         solve(candidates,target-candidates[x],x,ds,ans);
            ds.pop_back();
        }
        
        solve(candidates,target,x+1,ds,ans);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> ds;
        vector<vector<int>> ans;
        solve(candidates,target,0,ds,ans);
            return ans;
        
    }
};