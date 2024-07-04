class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {

        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);

        int five = 0;
        int ten = 0;

        for (int i = 0; i < bills.size(); i++) {
            if (bills[i] == 5) {
                five++;
            } else if (bills[i] == 10) {
                ten++;
                if (five > 0) {
                    five--;
                } else
                    return false;
            } else {
                if (ten > 0 && five > 0) {
                    ten--;
                    five--;
                } else if (five >= 3) {
                    five -= 3;
                } else {
                    return false;
                }
            }
        }

        return true;
    }
};
