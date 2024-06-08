int speedup = []{ios::sync_with_stdio(0); cin.tie(0); return 0;}();
class Solution {
public:
    bool isPossibleDivide(vector<int>& hand, int groupSize) {
        
        int n = hand.size();
        if (n % groupSize != 0) return false;
        if (groupSize == 1) return true;

        unordered_map<int, int> countMap;
        for (int num : hand) {
            countMap[num]++;
        }

        sort(hand.begin(), hand.end());

        for (int card : hand) {
            if (countMap[card]) {
                for (int i = 0; i < groupSize; i++) {
                    if (countMap[card + i] == 0) return false;
                    countMap[card + i]--;
                }
            }
        }
        return true;
    }
};

