class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        ios::sync_with_stdio(0); cin.tie(0);
        int size = nums.size();
        k = k % size;
        vector<int>rotated(size);
        int swag = (size-k);

        for(int i = 0; i < size; ++i){
            rotated[i] = nums[(swag+i)%size];
        }

        for(int i = 0; i < size; ++i){
            nums[i] = rotated[i];
        }


    }
};
