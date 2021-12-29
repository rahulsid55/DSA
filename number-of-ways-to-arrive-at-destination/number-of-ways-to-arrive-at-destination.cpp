typedef long long ll;
const ll mod=1e9+7;
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> graph(n);
        for(auto x: roads){
            graph[x[0]].push_back({x[1],x[2]});
            graph[x[1]].push_back({x[0],x[2]});
        }
        vector<ll> dis(n,LLONG_MAX);
        vector<ll> path(n,0);
        path[0]=1;
        dis[0]=0;
        priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;
        pq.push({0,0});
        while(!pq.empty())
        {
            pair<ll,ll> p=pq.top();
            pq.pop();
            for(auto l : graph[p.second])
            {
                ll cost=l.second;
                ll node=l.first;
                if(dis[node]>cost+dis[p.second]){
                    dis[node]=cost+dis[p.second];
                    path[node]=path[p.second];
                    path[node]%=mod;
                    pq.push({dis[node],node});
                }
                else if(dis[node]==cost+p.first){
                    path[node]+=path[p.second];
                    path[node]%=mod;
                }
                    
            }
        }
        return path[n-1];
    }
};