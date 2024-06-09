class Solution {
public:
    string getPermutation(int n, int k) {
        string ans = "";
        // simple code explained step by step with comments
        // create a list of numbers to be used in the permutation
        // our approach will be to find the first digit of the kth permutation and then remove it from the list and repeat the process for the remaining digits
        vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        // create a list of factorials to be used in the calculation
        vector<int> fact;
        fact.push_back(1);
        for (int i = 1; i < n; i++) {
            fact.push_back(fact[i - 1] * i);
        }
        // decrement k as we are using 0 based indexing
        k--;
        // iterate over the digits of the permutation
        for (int i = n - 1; i >= 0; i--) {
            // find the index of the digit to be used in the permutation
            int index = k / fact[i];
            // append the digit to the answer
            ans += to_string(nums[index]);
            // remove the digit from the list
            nums.erase(nums.begin() + index);
            // update k to find the next digit
            k %= fact[i];
        }
        // return the answer
        


        return ans;
    }
};
