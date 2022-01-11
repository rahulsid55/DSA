class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int col=image[sr][sc];
        queue<pair<int,int>> q;
        int m=image.size();
        int n=image[0].size();
        vector<vector<int>> visited(m,vector<int>(n,0));
        q.push({sr,sc});
        int dx[4]={0,0,1,-1};
        int dy[4]={1,-1,0,0};
        visited[sr][sc]=1;
        image[sr][sc]=newColor;
        while(!q.empty()){
            int i=q.front().first;
            int j=q.front().second;
            q.pop();
            for(int k=0;k<4;k++){
                int newi=i+dx[k];
                int newj=j+dy[k];
                if(newi>=0 and newj>=0 and newi<m and newj<n and visited[newi][newj]==0 and  image[newi][newj]==col)
                {
                    image[newi][newj]=newColor;
                    visited[newi][newj]=1;
                    q.push({newi,newj});
                }
            }
        }
        return image;
        
    }
};