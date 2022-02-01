class Solution {
public:
    bool unions(int x,int y,int start,int end){
        if((start>=x and start<=y and  end>=y) or (start>=x and end<=y)){
            
            return true;
        }
        return false;
    }
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int i=0,n=intervals.size();
        //push until start
        while(i<n and intervals[i][0]<=newInterval[0]){
                ans.push_back(intervals[i]);
                i++;
        }
       //push new Interval
        if(ans.size()==0 || ans.back()[1]<newInterval[0]){
            ans.push_back(newInterval);
        }
        else{
              ans.back()[0]=min(ans.back()[0],newInterval[0]);
              ans.back()[1]=max(ans.back()[1],newInterval[1]);
              
        }
        
        while(i<n and ans.back()[1]>=intervals[i][0]){
              ans.back()[0]=min(ans.back()[0],intervals[i][0]);
              ans.back()[1]=max(ans.back()[1],intervals[i][1]);
            i++;
              }
        while(i<n){
            ans.push_back(intervals[i]);
            i++;
            
        }
        return ans;
    }
};