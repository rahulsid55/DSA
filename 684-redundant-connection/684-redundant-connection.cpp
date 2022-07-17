class Solution {
public:
    int parent[10001];
    int rank[10001];
    int findPar(int node)
    {
        if(node==parent[node])
            return node;
        return parent[node]=findPar(parent[node]);
    }
    void union_of(int u, int v)
    {
        u=findPar(u);
        v=findPar(v);
        if(rank[u]<rank[v])
        {
            parent[u]=v;
        }
        else if(rank[u]>rank[v])
            parent[v]=u;
        else 
        {
            parent[u]=v;
            rank[v]++;
        }
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> ans;
        int n=edges.size();
        for(int i=1;i<=n;i++){
            parent[i]=i;
            rank[i]=0;
        }
        for(auto it: edges){
            if(findPar(it[0])==findPar(it[1])){
                ans=it;
            }
            else{
                union_of(it[0],it[1]);
            }
        }
        for(int i=1;i<=n;i++) cout<<parent[i]<<" ";
        return ans;
        
    }
};