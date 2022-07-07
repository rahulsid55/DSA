class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,pair<int,int>>>pq;
        
        for(auto i : points){
            pq.push(make_pair(i[0]*i[0]+i[1]*i[1], make_pair(i[0],i[1])));
            if(pq.size()>k){
                pq.pop();
            }
        }
        
        vector<vector<int>> ans;
        while(!pq.empty()){
            vector<int> temp;
            temp.push_back(pq.top().second.first);
            temp.push_back(pq.top().second.second);
            ans.push_back(temp);
            pq.pop();  
        }
        
        return ans;
    }
};