const auto init = [](){
       std::cin.tie(nullptr);
       std::cout.tie(nullptr);
       std::ios_base::sync_with_stdio(false);
       return nullptr;
}();
class Solution {
public:
  bool check(vector<int>& nums) {

    int n = nums.size();
    int min_index = distance(nums.begin(), min_element(nums.begin(), nums.end()));

    bool violater = false; 

    for (int i = 0; i < n; i++) {
      
      if (nums[(min_index + i) % n] > nums[(min_index + i + 1) % n]) {
        
        if (violater) {
          return false; 
        }
        
        violater = true;

        if (nums[(min_index + i + 1) % n] != nums[min_index]) {
          return false;
        }

      }
    }

    return true; 
  }
};

