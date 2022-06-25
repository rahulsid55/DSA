class KthLargest {
public:
    int min(int a,int b){
        if(a>b) return b;
        return a;
    }
    int x;
    priority_queue <int, vector<int>, greater<int> > pq;
    KthLargest(int k, vector<int>& nums) {
        x=k;
        for(int i=0;i<min(k,nums.size());i++){
            pq.push(nums[i]);
        }
        for(int i=k;i<nums.size();i++){
            if(nums[i]>pq.top()){
                pq.pop();
                pq.push(nums[i]);
            }
        }
        
    }
    
    int add(int val) {
        if(pq.size()<x){
            pq.push(val);
        }
        else if(pq.top()<val){
            pq.pop();
            pq.push(val);
        }
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */