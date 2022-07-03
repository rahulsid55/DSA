class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        //carrying previous results forward
        int n=nums.size();
        int down=1,up=1;
        for(int i=1;i<n;i++){
            if(nums[i]>nums[i-1]){
                up=1+down;
            }
            else if(nums[i]<nums[i-1]){
                down=1+up;
            }
        }
        return max(down,up);
    }
};