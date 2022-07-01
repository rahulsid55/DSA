class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int add) {
        int n=capacity.size();
        int diff[n];
        for(int i=0;i<n;i++){
            diff[i]=capacity[i]-rocks[i];
        }
        sort(diff,diff+n);
        int c=0;
        for(int i=0;i<n;i++){
            //cout<<diff[i]<<" ";
            add=add-diff[i];
            if(add>=0) c++;
            else break;
        }
        return c;
        
    }
};