class Solution {
    
public:
    int countPairs(vector<int>& del) {
        int mod=1e9+7;
        map<int,int> mp;
        int n=del.size();
        int ans=0;
        for(int i=0;i<n;i++){
            int power=1;
            for(int j=0;j<22;j++){
                if(mp.count(power-del[i])){
                    ans+=mp[power-del[i]];
                    ans%=mod;
                }
                power<<=1;
            }
            mp[del[i]]++;
        }
        return ans;
    }
};