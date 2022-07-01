class Solution {
public:
    int ans=INT_MAX;
    void help(vector<int> &cook,int k,vector <int> &cnt,int id){
        if(id>=cook.size()){
            ans=min(ans,*max_element(cnt.begin(),cnt.end()));
            return;
        }
        for(int i=0;i<k;i++){
            cnt[i]+=cook[id];
            help(cook,k,cnt,id+1);
            cnt[i]-=cook[id];
        }
    }
    int distributeCookies(vector<int>& cook, int k) {
        vector<int> cnt(k,0);
        help(cook,k,cnt,0);
        return ans;
        
    }
};