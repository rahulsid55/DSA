class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        if(n<2) return n;
        int ind=2;
        for(int i=2;i<n;i++){
            if(nums[i]!=nums[ind-2]){
                swap(nums[ind++],nums[i]);
            }
        }
        return ind;
    }
};