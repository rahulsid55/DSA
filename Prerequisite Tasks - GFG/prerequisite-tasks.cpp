// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    bool isCycle(int node,vector<int> graph[],vector<int> &vis,vector<int> &dfsvis){
        dfsvis[node]=1;
        vis[node]=1;
        for(auto i: graph[node]){
            if(!vis[i]){
                if(isCycle(i,graph,vis,dfsvis)) return true;
            }
            else if(dfsvis[i]){
                return true;
            }
        }
        dfsvis[node]=0;
        return false;
    }
	bool isPossible(int N, vector<pair<int, int> >& pre) {
	    vector<int> graph[N];
	    for(auto i: pre){
	        graph[i.second].push_back(i.first);
	    }
	    vector<int> vis(N,0),dfsvis(N,0);
	    for(int i=0;i<N;i++){
	        if(!vis[i])
	        {
	            if(isCycle(i,graph,vis,dfsvis)){
	                return false;
	            }
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
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}  // } Driver Code Ends