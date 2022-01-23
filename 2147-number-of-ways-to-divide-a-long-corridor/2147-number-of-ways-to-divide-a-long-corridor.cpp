
int mod=1000000007;
class Solution {
public:
    int numberOfWays(string corridor) {
        vector<int> pos;
        for(int i=0;i<corridor.size();i++){
            if(corridor[i]=='S')
            {
                //cout<<i<<" ";
               pos.push_back(i);
            }
        }
        if(pos.size()==0 or pos.size()%2==1) return 0;
        int prev=pos[1];
        long long ans=1;
        for(int i=2;i<pos.size()-1;i+=2){
            int x=pos[i]-prev;
            ans=(ans*x)%mod;
            prev=pos[i+1];
        }
        return ans;
        
    }
};