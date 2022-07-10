class Solution {
public:
    int cost=0,x=0;
    void dfs(int node,vector<int> adj[],vector<int> &time){
        x+=time[node];
        cost=max(cost,x);
        for(auto it: adj[node]){
            dfs(it,adj,time);
        }
        x-=time[node];
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<int> adj[n];
        for(int i=0;i<n;i++){
            if(manager[i]!=-1)
            adj[manager[i]].push_back(i);
        }
        dfs(headID,adj,informTime);
        return cost;
        
    }
};