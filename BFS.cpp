vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<int> ans;
        queue <int> q;
        q.push(0);
        int visited[V];
        for(int i=0;i<V;i++) visited[i]=0;
        visited[0]=1;
        while(!q.empty()){
            int x=q.front();
            q.pop();
            ans.push_back(x);
            for(auto i: adj[x]){
                if(visited[i]==0){
                    q.push(i);
                    visited[i]=1;
                }
            }
        }
        return ans;
    }
