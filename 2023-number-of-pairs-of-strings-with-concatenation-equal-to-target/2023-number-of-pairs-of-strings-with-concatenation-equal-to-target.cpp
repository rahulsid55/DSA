class Solution {
public:
    int numOfPairs(vector<string>& nums, string target) {
        map<string,int> mp;
        for(auto i: nums){
            mp[i]++;
        }
        int i=0,cnt=0,n=target.size();
        while(i<n-1){
            string f=target.substr(0,i+1);
            string s=target.substr(i+1);
            //cout<<f<<" "<<s<<endl;
            if(f==s){
                if(mp.count(f)){
                    cnt+=(mp[f])*(mp[f]-1);
                }
            }
            else{
                if(mp.count(f) and mp.count(s)){
                    cnt+=(mp[f])*(mp[s]);
                }
            }
            i++;
        }
        return cnt;
        
        
    }
};