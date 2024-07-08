/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        maxPath(root, maxi);
        return maxi;
    }

    int maxPath(TreeNode* node, int &maxi){
        if(!node) return 0;

        int left = maxPath(node->left, maxi);
        int right = maxPath(node->right, maxi);
        if(left < 0) left = 0;
        if(right < 0) right = 0;
        maxi = max(maxi, left + right + node->val);
        return max(left, right) + node->val;
    }
};
