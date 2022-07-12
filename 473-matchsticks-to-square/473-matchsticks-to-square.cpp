class Solution {
public:
    int a=0,b=0,c=0,d=0,t;
    bool solve(vector<int> &sticks,int i){
        if(i==sticks.size()){
            if(a==0 and b==0 and c==0 and d==0) return true;
            return false;
        }
            if(a>=sticks[i]){
                a-=sticks[i];
                if(solve(sticks,i+1)) return true;
                a+=sticks[i];
            }
            if(b>=sticks[i]){
                b-=sticks[i];
                if(solve(sticks,i+1)) return true;;
                b+=sticks[i];
            }
            if(c>=sticks[i]){
                c-=sticks[i];
                if(solve(sticks,i+1)) return true;
                c+=sticks[i];
            }
            if(d>=sticks[i]){
                d-=sticks[i];
                if(solve(sticks,i+1)) return true;;
                d+=sticks[i];
            }
        return false;
    }
    bool makesquare(vector<int>& sticks) {
        int sum=0;
        for(auto it: sticks){
            sum+=it;
        }
        if(sum%4!=0) return false;
        t=sum/4;
        a=b=c=d=t;
        sort(sticks.rbegin(),sticks.rend());
        return solve(sticks,0);
        
        
    }
};