class Solution {
public:
    int visited[10001];
    vector<int> ans;
    pair<int,int> dfs(int node,vector<int> adj[],vector<int> quiet){
        if(adj[node].size()==0) {
            ans[node]=node;
            return {quiet[ans[node]],ans[node]};
        }
        if(visited[node]==1){
            return {quiet[ans[node]],ans[node]};
        }
        ans[node]=node;
        for(auto it: adj[node]){
                pair<int,int> x=dfs(it,adj,quiet);
                if(quiet[ans[node]]>x.first){
                    ans[node]=x.second;
                }
        }
        visited[node]=1;
        return {quiet[ans[node]],ans[node]};
        
    }
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n=quiet.size();
        vector<int> adj[n];
        for(auto it: richer){
            adj[it[1]].push_back(it[0]);
        }
        ans.resize(n);
        for(int i=0;i<n;i++){
            if(!visited[i]){
                ans[i]=i;
                 pair<int,int> x=dfs(i,adj,quiet);
                //cout<<x.first<<" "<<x.second<<endl;
                if(quiet[ans[i]]>x.first){
                    ans[i]=x.second;
                }
            }
        }
        return ans;
    }
};