class Solution {
public:
    int vis[100001];
    vector<vector<int>> ans;
    int timer=0;
    int tin[100001];
    int low[100001];
    void dfs(int node,int par,vector<int> adj[]){
        vis[node]=1;
        tin[node]=low[node]=timer++;
        for(auto it: adj[node]){
            if(it==par) continue;
            if(!vis[it]){
                dfs(it,node,adj);
                low[node]=min(low[node],low[it]);
                if(low[it]>tin[node]){
                    ans.push_back({it,node});
                }
            }
            else{
                low[node]=min(tin[it],low[node]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];
        for(auto it: edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        for(int i=0;i<n;i++){
            if(vis[i]==0)
                dfs(i,-1,adj);
        }
        return ans;
    }
};