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
    int dfsheight(TreeNode* root){
        if(!root){
            return 0;
        }
        int lh = dfsheight(root->left);
        int rh = dfsheight(root->right);

        if(lh == -1 || rh == -1 || abs(lh-rh)>1){
            return -1;
        }

        return 1 + max(lh, rh);
    }
    bool isBalanced(TreeNode* root) {
        return dfsheight(root) != -1;
    }
};
