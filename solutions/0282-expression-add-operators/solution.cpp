class Solution {
public:
    void dfs(const string& num, int target, int index, string expr,
             long long currValue, long long lastOperand,
             vector<string>& results) {
        if (index == num.size()) {
            if (currValue == target) {
                results.push_back(expr);
            }
            return;
        }

        for (int i = index; i < num.size(); i++) {

            if (i != index && num[index] == '0')
                break;

            string currStr = num.substr(index, i - index + 1);
            long long currNum = stoll(currStr);

            if (index == 0) {
                dfs(num, target, i + 1, currStr, currNum, currNum, results);
            } else {
                dfs(num, target, i + 1, expr + "+" + currStr,
                    currValue + currNum, currNum, results);
                dfs(num, target, i + 1, expr + "-" + currStr,
                    currValue - currNum, -currNum, results);
                dfs(num, target, i + 1, expr + "*" + currStr,
                    currValue - lastOperand + (lastOperand * currNum),
                    lastOperand * currNum, results);
            }
        }
    }
    vector<string> addOperators(string num, int target) {
        vector<string> results;
        dfs(num, target, 0, "", 0, 0, results);
        return results;
    }
};
