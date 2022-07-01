class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        vector <pair<int,int>> v;
        for(auto it: boxTypes){
            v.push_back({it[1],it[0]});
        }
        int i=0,c=0,n=v.size();
        sort(v.begin(),v.end(),greater<pair<int,int>> ());
        while(truckSize and i<n){
            int boxes=min(truckSize,v[i].second);
            truckSize-=boxes;
            c+=(boxes*(v[i].first));
            i++;
        }
        return c;
        
    }
};