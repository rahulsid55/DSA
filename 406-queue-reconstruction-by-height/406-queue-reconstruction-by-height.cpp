class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        int n=people.size();
        sort(people.begin(),people.end());
        vector<vector<int>> ans(n);
        vector<int> visited(n,-1);
        for(int i=0;i<n;i++){
            int ct=people[i][1];
            for(int j=0;j<n;j++){
                if(ct==0 and visited[j]==-1){
                    ans[j]=people[i];
                    visited[j]=1;
                    break;
                }
                else{
                    if(visited[j]==-1 || ans[j][0]>=people[i][0]){
                        ct--;
                    }
                }
            }
        }
        return ans;
    }
};