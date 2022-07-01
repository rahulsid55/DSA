class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n=nums.size();
        vector<long long> num(n);
        num[0]=nums[0];
        for(int i=1;i<nums.size();i++){
            num[i]=num[i-1]+nums[i];
        }
        int ct=0;
        for(int i=0;i<n-1;i++){
            if(num[i]>=(num[n-1]-num[i])){
                ct++;
            }
        }
        return ct;
        
    }
};