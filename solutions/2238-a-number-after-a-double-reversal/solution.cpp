class Solution {
public:
    bool isSameAfterReversals(int num) {
        if(num%10 == 0 && num > 0) return false;
        return true;
    }
};
