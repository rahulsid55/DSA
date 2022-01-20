// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
    bool dfs(int node,vector<int> &color,vector<int> &visited,vector<int>adj[]){
        visited[node]=1;
        for(auto it: adj[node]){
            if(!visited[it]){
                color[it]=1-color[node];
                if(dfs(it,color,visited,adj)==false)
                return false;
            }
            else if(color[it]==color[node])
            return false;
        }
        return true;
    }
public:
	bool isBipartite(int V, vector<int>adj[]){
	    vector<int> color(V),visited(V,0);
	    for(int i=0;i<V;i++){
	        if(!visited[i]){
	            color[i]=0;
	            if(dfs(i,color,visited,adj)==false)
	            return false;;
	        }
	    }
	    return true;
	    
	}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}  // } Driver Code Ends