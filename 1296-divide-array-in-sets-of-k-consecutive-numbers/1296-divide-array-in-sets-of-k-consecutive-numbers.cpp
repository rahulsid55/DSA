class Solution {
public:
    bool isPossibleDivide(vector<int>& hand, int g) {
        map<int,int> mp;
        for(auto it: hand){
            mp[it]++;
        }
        int n=hand.size();
        if(n%g!=0) return false;
        while(mp.size()){
            int x=mp.rbegin()->first;
            for(int i=0;i<g;i++){
                //cout<<x<<endl;
                if(mp.count(x)==0) return false;
                mp[x]--;
                if(mp[x]==0) mp.erase(x);
                x--;
            }
            //cout<<"#";
        }
        return true;

        
    }
};