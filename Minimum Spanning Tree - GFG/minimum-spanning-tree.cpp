// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> parent(V,-1),mst(V,0),cost(V,INT_MAX);
        cost[0]=0;
        int ans=0;
        pq.push({0,0});
        while(!pq.empty())
        { 
            int u = pq.top().second; 
            pq.pop(); 
            
            mst[u] = 1; 
            
            for (auto it : adj[u]) {
                int v = it[0];
                int weight = it[1];
                if (mst[v] == 0 && weight < cost[v]) {
                    parent[v] = u;
    		cost[v] = weight; 
                    pq.push({cost[v], v});    
                }
            }
                
        }
        for(auto j:cost){
            ans+=j;
        }
        return ans;
    }
};


// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends