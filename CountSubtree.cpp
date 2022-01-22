#include<bits/stdc++.h>
using namespace std;
int dfs(vector <int> &dp,vector<int> adj[],int node,vector<int> &visited){
    if(visited[node]==1){
        return dp[node];
    }
    visited[node]=1;
    for(auto u: adj[node]){
        dp[node]+=dfs(dp,adj,u,visited);
    }
    //cout<<dp[node];
    return dp[node];
}
vector<int> subtreeProblem (int n, vector<vector<int>> edges, vector<int> queries)
{
    vector<int> dp(n+1,1),visited(n+1,0);
    vector<int> ans;
    vector<int> adj[n+1];
    for(auto i : edges){
        adj[i[0]].push_back(i[1]);
    }
    for(int i : queries){
            int x=dfs(dp,adj,i,visited);
            ans.push_back(x);
        }
    return ans;
    
}
int main(){
    int n=5;
    vector<vector<int>> edges;
    edges.push_back({3,2});
    edges.push_back({3,1});
    edges.push_back({3,4});
    edges.push_back({4,5});
    vector<int> queries;
    queries.push_back(1);
    queries.push_back(2);
    queries.push_back(3);
    queries.push_back(4);
    queries.push_back(5);
    vector<int> ans=subtreeProblem(n,edges,queries);
    for(auto i: ans){
        cout<<i<<" ";
    }
    
}
