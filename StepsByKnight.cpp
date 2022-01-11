// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int n)
	{
	    vector<vector<int>> vis(n+1,vector<int>(n+1,0));
	    int i=KnightPos[0];
	    int j=KnightPos[1];
	    int x=TargetPos[0];
	    int y=TargetPos[1];
	   
	    int dx[8]={2,-2,2,-2,1,-1,1,-1};
	    int dy[8]={1,-1,-1,1,2,-2,-2,2};
	    queue<pair<pair<int,int>,int>> q;
	    
	    q.push({{i,j},0});
	    
	    vis[i][j]=1;
	    
	    while(!q.empty()){
	        int i=q.front().first.first;
	        int j=q.front().first.second;
	        int dist=q.front().second;
	        q.pop();
	        if(i==x and j==y){
	            return dist;
	        }
	        for(int k=0;k<8;k++){
	            int newi=i+dx[k];
	            int newj=j+dy[k];
	            if(newi>0 and newj>0 and newi<=n and newj<=n and vis[newi][newj]==0)
	            {
	                q.push({{newi,newj},1+dist});
	                vis[newi][newj]=1;
	            }
	        }
	    }
	    return -1;
	}
	
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends
