class Solution {
public:
    int dj(int n,vector<vector<pair<int,int>>> g,int src,int des,int k){
        set<pair<pair<int,int>,int>> ds;
        ds.insert({{0,src},0});
        while(!ds.empty()){
            auto it=ds.begin();
            int cost=it->first.first;
            int node=it->first.second;
            int lvl=it->second;
            ds.erase(it);
            if(lvl>k+1){
                continue;
            }
            if(node==des) return cost;
            for(auto [v,d] : g[node])
            {
                if(lvl<=k){
                    ds.insert({{cost+d,v},lvl+1});
                }
            }
        }
                  return INT_MAX;
    }
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> g(n);
        for(auto edge: flights){
            g[edge[0]].push_back({edge[1],edge[2]});
        }
        int ans=dj(n,g,src,dst,k);
        return ans==INT_MAX?-1:ans;
    }
};