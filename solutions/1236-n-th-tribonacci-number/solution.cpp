const auto init = [](){
       std::cin.tie(nullptr);
       std::cout.tie(nullptr);
       std::ios_base::sync_with_stdio(false);
       return nullptr;
}();

class Solution {
public:
    int tribonacci(int n) {
        if(n == 0) return 0;
        if(n == 1 || n == 2) return 1;

        
        int one = 0;
        int two = 1;
        int three = 1;
        int curr = 0;
        for(int i = 3; i <= n; i++) {
            curr = one + two + three;
            one = two;
            two = three;
            three = curr;
        }

        return curr;
    }
};

