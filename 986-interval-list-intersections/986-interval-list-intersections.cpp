class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& first, vector<vector<int>>& second) {
        int n1=first.size();
        int n2=second.size();
        vector<vector<int>> ans;
        int i=0,j=0;
        while(i<n1 and j<n2){
            if(first[i][0]<=second[j][1] and first[i][1]>=second[j][0]){
                ans.push_back({max(first[i][0],second[j][0]),min(first[i][1],second[j][1])});
                
            }
            if(first[i][1]<=second[j][1]){
                    i++;
                }
            else if(first[i][1]>=second[j][1]){
                j++;
            }
        }
    return ans;
    }
};