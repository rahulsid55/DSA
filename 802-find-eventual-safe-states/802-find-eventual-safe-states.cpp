class Solution {
public:
    set<int> ispresent;
    int visited[100001];
    int dfsvis[100001];
    bool dfs(int node,vector<vector<int>>& graph){
        visited[node]=1;
        dfsvis[node]=1;
        for(auto it: graph[node]){
            if(visited[it]==0){
                if(dfs(it,graph)){
                    ispresent.insert(it);
                    return true;
                }
            }
            else if(dfsvis[it]){
                return true;
            }
        }
        dfsvis[node]=0;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        for(int i=0;i<n;i++){
            if(visited[i]==0){
                if(dfs(i,graph)){
                    ispresent.insert(i);
                }
            }
        }
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(!ispresent.count(i))
                ans.push_back(i);
        }
        return ans;
        
    }
};