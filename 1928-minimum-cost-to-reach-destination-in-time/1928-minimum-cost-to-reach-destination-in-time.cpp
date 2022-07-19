class Solution {
public:
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& fees) {
        set<vector<int>> s;
        int n=fees.size();
        vector<pair<int,int>> adj[n];
        for(auto it: edges){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        vector<int> cost(n,2000);
        cost[0]=0;
        s.insert({fees[0],0,0});
        while(!s.empty()){
            vector<int> x=*s.begin();
            s.erase(s.begin());
            if(x[1]==n-1){
                return x[0];
            }
            for(auto it: adj[x[1]]){
                if(x[2]+it.second<cost[it.first] and x[2]+it.second<=maxTime){
                    cost[it.first]=x[2]+it.second;
                    s.insert({x[0]+fees[it.first],it.first,x[2]+it.second});
                }
            }
        }
        return -1;
        
    }
};