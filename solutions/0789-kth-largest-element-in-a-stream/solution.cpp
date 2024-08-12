class KthLargest {
public:
    int kk;
    priority_queue<int>swag;
    KthLargest(int k, vector<int>& nums) {
        for(int n : nums){
            swag.push(-n);
        }
        while(swag.size() > k){
            swag.pop();
        }
        kk = k;
    }
    
    int add(int val) {
        swag.push(-val);
        if(swag.size() > kk) swag.pop();
        return (-(swag.top()));
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
