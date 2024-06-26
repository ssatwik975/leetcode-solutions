auto speedup(){ios_base::sync_with_stdio(false);cin.tie(nullptr); cout.tie(nullptr);};
class Solution {
public:
    int stoi(char c) {
        return c - '0';
    }
    
    string multiply(string num1, string num2) {
        speedup();
        if (num1 == "0" || num2 == "0")
            return "0";
        
        int n = num1.size();
        int m = num2.size();
        
        vector<int> steps(n + m, 0);
        
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                int prod = stoi(num1[i]) * stoi(num2[j]);
                int sum = prod + steps[i + j + 1];
                
                steps[i + j] += sum / 10;
                steps[i + j + 1] = sum % 10;
            }
        }
        
        // Convert steps vector to string (skip leading zeros)
        int start = 0;
        while (start < steps.size() && steps[start] == 0) {
            start++;
        }
        
        string result = "";
        for (int i = start; i < steps.size(); i++) {
            result += to_string(steps[i]);
        }
        
        return result;
    }
};

