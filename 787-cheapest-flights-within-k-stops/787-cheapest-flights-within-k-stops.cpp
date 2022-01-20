class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
     vector<vector<pair<int,int>>>v(n);
        k+=1;
     for(int i=0;i<flights.size();i++)
     {
        int x=flights[i][0];
        int y=flights[i][1];
        int z=flights[i][2];
        v[x].push_back({y,z});
     }
     queue<pair<int,int>>q;
     q.push({src,0});
     vector<int>vis(n,INT_MAX);
     vis[src]=0;
     while(q.size()!=0)
     {
        int size=q.size();
        while(size--)
        {
            auto [x,y]=q.front();
            q.pop();
            if(vis[x]>y)vis[x]=y;
            for(auto val:v[x]){
                if(vis[val.first]==INT_MAX)
                q.push({val.first,val.second+y});
                else if(vis[val.first]>val.second+y){
                    q.push({val.first,val.second+y});
                }
            }
        }
        if(k==0){
            break;
        }
         k--; 
     }
     if(vis[dst]!=INT_MAX) return vis[dst];
     return -1;
    }
};