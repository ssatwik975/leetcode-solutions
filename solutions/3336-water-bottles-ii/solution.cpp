const auto init = [](){
       std::cin.tie(nullptr);
       std::cout.tie(nullptr);
       std::ios_base::sync_with_stdio(false);
       return nullptr;
}();
class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int drunk = numBottles;
        int empty = numBottles;
        int flag = 1;
        while(flag){
            flag = 0;
            if (numExchange <= empty) {
                empty -= numExchange;
                drunk++;
                empty++;
                numExchange++;
                flag = 1;
            }
        }
        return drunk;
    }
};
