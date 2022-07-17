class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>> adj[n+1];
        for(auto it: times){
            adj[it[0]].push_back({it[1],it[2]});
        }
        int visited[n+1];
        memset(visited,0,sizeof(visited));
        int cost[n+1];
        for(int i=1;i<=n;i++) cost[i]=INT_MAX;
        cost[k]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,k});
        for(int i=1;i<n;i++){
            while(!pq.empty()){
                pair<int,int> temp=pq.top();
                pq.pop();
                int c=temp.first;
                int node=temp.second;
                //cout<<c<<" "<<node<<endl;
                visited[node]=1;
                for(auto it: adj[node]){
                    //cout<<c+it.second<<" "<<cost[it.first]<<" ";
                    if(visited[it.first]==0 and c+it.second<cost[it.first]){
                        cost[it.first]=c+it.second;
                        pq.push({cost[it.first],it.first});
                        //cout<<it.first;
                    }
                }
            }
        }
        int x=0;
        for(int i=1;i<=n;i++) x=max(x,cost[i]);
        return x==INT_MAX?-1:x;
    }
};