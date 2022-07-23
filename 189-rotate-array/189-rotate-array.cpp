class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        k=k%n;
        int t=n-k;
        vector<int> x(nums.begin(),nums.begin()+t);
        vector<int> y(nums.begin()+t,nums.end());
        for(int i=0;i<k;i++){
            nums[i]=y[i];
        }
        for(int i=k;i<n;i++){
            nums[i]=x[i-k];
        }
        
    }
};