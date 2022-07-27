class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int pos=-1;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]>nums[i+1]){
                if(pos!=-1) return false;
                pos=i;
            }
            
        }
        //2 4 2
        //4 2 8
        return (pos==-1 || pos==0 || pos==nums.size()-2 || nums[pos-1]<=nums[pos+1] || nums[pos]<=nums[pos+2]);
        
    }
};