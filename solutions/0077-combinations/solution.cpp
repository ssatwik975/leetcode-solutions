class Solution {
public:
    void solve(int i, vector<int> &ds, vector<vector<int>> &ans, int n, int k){
        if(ds.size()==k){
            ans.push_back(ds);
            return;
        }
        if(i > n){
            return;
        }
        ds.push_back(i);
        solve(i+1, ds, ans, n, k);
        ds.pop_back();
        solve(i+1, ds, ans, n, k);
        
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> ds;
        vector<vector<int>> ans;
        solve(1, ds, ans, n, k);
        return ans;
    }
};



// #include <iostream>
// #include <vector>
// #include <string>

// using namespace std;

// string toString(vector<int> v) {
//     string ans = "[";
//     for (int i: v) {
//         ans += i + '0';
//         ans += ", ";
//     }
//     ans = ans.substr(0, ans.length() - 2) + "]";
//     return ans;
// }

// string toString(vector<vector<int>> v) {
//     string ans = "[";
//     for (vector<int> i: v) {
//         ans += toString(i);
//         ans += ", ";
//     }
//     ans = ans.substr(0, ans.length() - 2) + "]";
//     return ans;
// }

// class Solution {
// public:
//     vector<vector<int>> combine(int n, int k) {
//         vector<vector<int>> ans;
//         vector<int> c(k, 0); // vector of length k, all 0s
//         int i = 0;
//         while (i >= 0) {
//             // Increment element at index i
//             c[i]++;
//             cout << "Incremented element at index " << i << endl;
//             cout << toString(c) << endl;
            
//             /* Move index to the left if the element
//              * at index i has exceeded n.
//              */
//             if (c[i] > n) {
//                 i--;
//                 cout << "n exceeded at " << i+1 << ", moving index to the left" << endl;
//             }
            
//             /* If the index is at the end of the vector
//              * c, then (because the other conditions are
//              * obeyed), we know we have a valid combination,
//              * so push it to our ans vector<vector<>>
//              */
//             else if (i == k - 1) {
//                 ans.push_back(c);
//                 cout << "Combination found!" << endl;
//                 cout << "Added " << toString(c) << " as an answer!" << endl;
//             }
            
//             /* Move index to the right and set the
//              * element at that index equal to the
//              * element at the previous index.
//              * 
//              * Because of the increment at the beginning
//              * of this while loop, we ensure that the
//              * element at this index will be at least
//              * one more than its neighbor to the left.
//              */
//             else {
//                 i++;
//                 c[i] = c[i - 1];
//                 cout << "Moved index to the right, and copied the value"
//                 << " from the left" << endl;
//                 cout << toString(c) << endl;
//             }
//         }
//         return ans;
//     }
// };

// int main() {
//     Solution sol;
//     cout << toString(sol.combine(4, 2)) << endl;
//     return 0;
