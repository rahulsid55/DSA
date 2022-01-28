class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        vector<int> ans;
        for(auto i : points){
            ans.push_back(i[0]);
        }
        sort(ans.begin(),ans.end());
        int res=0;
        for(int i=1;i<ans.size();i++){
            res=max(res,ans[i]-ans[i-1]);
        }
        return res;
    }
};