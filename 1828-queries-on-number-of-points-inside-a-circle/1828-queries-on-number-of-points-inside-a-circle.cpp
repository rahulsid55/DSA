class Solution {
public:
    bool inside(int x,int y,int r,int x1,int y1){
        if((pow((x1-x),2)+pow((y-y1),2)-(r*r))<=0){
            return true;
        }
        return false;
    }
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        int n=points.size(),m=queries.size();
        vector<int> ans;
        for(int i=0;i<m;i++){
            int c=0;
            for(int j=0;j<n;j++){
                if(inside(queries[i][0],queries[i][1],queries[i][2],points[j][0],points[j][1])){
                    c++;
                }
            }
            ans.push_back(c);
        }
        return ans;
    }
};