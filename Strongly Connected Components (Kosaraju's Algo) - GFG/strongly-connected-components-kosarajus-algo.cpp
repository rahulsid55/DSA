// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
	void dfs(int node,vector<int> adj[],stack<int> &st,vector<int> &visited){
	    visited[node]=1;
	    for(auto it: adj[node]){
	        if(!visited[it]){
	            dfs(it,adj,st,visited);
	        }
	    }
	    st.push(node);
	}
	void dfs2(int node,vector<int> transpose[],vector<int> &visited){
	    visited[node]=1;
	    for(auto i: transpose[node]){
	        if(!visited[i]){
	            dfs2(i,transpose,visited);
	        }
	    }
	}
    int kosaraju(int V, vector<int> adj[])
    {
     //1.Toposort-to sort inorder of finishing time
     stack<int> st;
     vector<int> visited(V,0);
     for(int i=0;i<V;i++){
         if(visited[i]==0){
             dfs(i,adj,st,visited);
         }
     }
     //2.Make transpose
     vector<int> transpose[V];
     for(int i=0;i<V;i++){
         visited[i]=0;
         for(auto it: adj[i]){
             transpose[it].push_back(i);
         }
     }
     //3.dfs inorder in stack;
     int ans=0;
     while(!st.empty()){
         int x=st.top();
         st.pop();
         if(!visited[x]){
             ans++;
             dfs2(x,transpose,visited);
         }
     }
     return ans;
    }
};

// { Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends