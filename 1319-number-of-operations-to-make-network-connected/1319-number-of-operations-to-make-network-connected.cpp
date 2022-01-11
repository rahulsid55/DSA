class Solution {
public:
    void dfs(int node,int par,vector<int> &visited,vector<int> adj[],int &nodes,int &edges)
    {
        visited[node]=1;
        nodes++;
        for(auto i:adj[node])
        {
            if(!visited[i])
            {
                edges++;
                dfs(i,node,visited,adj,nodes,edges);
            }
            else if(i!=par)
            {
                edges++;
            }
            
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<int> adj[n];
        int extra=0;
        int comp=0;
        if(connections.size()<n-1) return -1;
        for(auto i: connections){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
            
        }
        vector<int> visited(n,0);
        for(int i=0;i<n;i++){
            if(!visited[i]){
                int nodes=0,edges=0;
                comp++;
                
                dfs(i,-1,visited,adj,nodes,edges);
                //cout<<nodes<<" "<<edges<<endl;
                int t=edges-(nodes-1);
                extra+=max(t,0);
            }
        }
        //cout<<extra;
        
            return comp-1;
        return -1;
        
        
    }
};