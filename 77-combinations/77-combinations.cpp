class Solution {
public:
    int visited[20]={0};
    void help(vector<int> ds,int k,vector<vector<int>> &ans,int n,int x){
        if(ds.size()==k){
            ans.push_back(ds);
            return ;
        }
        for(int i=x+1;i<=n;i++){
            ds.push_back(i);
            help(ds,k,ans,n,i);
            ds.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> ds;
        for(int i=1;i<=n;i++){
            ds.push_back(i);
            help(ds,k,ans,n,i);
            ds.pop_back();
            }
        return ans;
    }
};