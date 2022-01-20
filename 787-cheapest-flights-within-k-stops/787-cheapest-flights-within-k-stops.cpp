class Solution {
public:
    vector<pair<int,int> > adj[101];
    
    int dijkstra(int n, int src, int dst, int k){
        vector<int> dist(n+1,(1e9));
        dist[src]=0;
        set<pair<pair<int,int>,int> > setds;
        setds.insert({{0,src},0});
        int ans=1e9;
        while(!setds.empty()){
            auto it=setds.begin();
            int d=it->first.first;
            int u=it->first.second;
            int l=it->second;
            setds.erase(it);
            if(l>k+1)continue;
            if(u==dst){
                    return d;
            }
            for(auto [v,p]:adj[u])
            {
                if(d+p<(1e9) && l<=k){
                    setds.insert({{d+p,v},l+1});
                }
            }
        }
        return  ans;
        
    }
    
    
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        for(int i=0;i<flights.size();i++){
            adj[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }
        int ans=dijkstra(n,src,dst,k);
        return (ans>=(1e9))?-1:ans; 
    }
};