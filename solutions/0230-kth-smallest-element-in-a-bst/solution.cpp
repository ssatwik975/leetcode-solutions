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
    void inorder(TreeNode* root, int &swag, int& k){
        if(root == NULL) return;
        if(root->left) inorder(root->left, swag, k);
        if(k <= 0){
            return;
        }
        swag = root->val;
        k--;
        if(root->right) inorder(root->right, swag, k);
        return;
    }
    int kthSmallest(TreeNode* root, int k) {
        int ans;
        inorder(root, ans, k);
        return ans;
    }
};
