class Solution {
    
public:
    vector<double> generate(double a,double b){
        vector<double> x={a+b,b-a,a-b,a*b};
        if(abs(a)>0.000001) x.push_back(b/a);
        if(abs(b>0.000001)) x.push_back(a/b);
        return x;
    }
    bool solve(vector<double> &cards){
        int n=cards.size();
        if(n==1){
            //cout<<cards[0]<<" ";
            if(abs(cards[0]-24.0)<=0.000001){
                return true;
            }
        }
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                vector<double> temp=generate(cards[i],cards[j]);
                vector<double> next;
                for(int k=0;k<n;k++){
                    if(k!=i and k!=j){
                        next.push_back(cards[k]);
                    }
                }
                for(int k=0;k<temp.size();k++){
                    vector<double> cur=next;
                    cur.push_back(temp[k]);
                    if(solve(cur)) return true;
                  }
              
            }
        }
    return false;
}
    bool judgePoint24(vector<int>& cards) {
        vector<double> a(cards.begin(),cards.end());
        return solve(a);
        
    }
};