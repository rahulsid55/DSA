class Solution {
public:
    vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
        map<char,pair<int,int>> mp;
        mp['R']={0,1};
        mp['L']={0,-1};
        mp['U']={-1,0};
        mp['D']={1,0};
        vector<pair<int,int>> v(s.length());
        v[0]=mp[s[0]];
        for(int i=1;i<s.length();i++){
            v[i]={v[i-1].first+mp[s[i]].first,v[i-1].second+mp[s[i]].second};
        }
        vector<int> ans(s.length());
        int len=s.length();
        for(int i=0;i<len;i++){
            for(int j=i;j<len;j++){
                pair<int,int> x;
                if(i==0){
                     x={v[j].first,v[j].second}; 
                }
                else{
                  x={v[j].first-v[i-1].first,v[j].second-v[i-1].second};   
                }
                
                x={x.first+startPos[0],x.second+startPos[1]};
                if(x.first>=0 and x.first<n and x.second>=0 and x.second<n){
                    ans[i]=j-i+1;
                }
                else{
                    break;
                }
            }
        }
        return ans;
    }
};