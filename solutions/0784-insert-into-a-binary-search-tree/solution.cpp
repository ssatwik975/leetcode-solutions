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
    TreeNode* saviour(TreeNode* root, int val){
        if (root == NULL) return NULL;
        if (root->left == NULL && root->right == NULL) {
            return root;
        } else if (root->val > val) {
            if (root->left == NULL) {
                return root;
            } else {
                return saviour(root->left, val);
            }
        } else {
            if (root->right == NULL) {
                return root;
            } else {
                return saviour(root->right, val);
            }
        }
    }

    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == NULL) {
            return new TreeNode(val);
        }
        
        TreeNode* joint = saviour(root, val);
        TreeNode* swag = new TreeNode(val);
        
        if (joint->val > val) {
            joint->left = swag;
        } else {
            joint->right = swag;
        }
        
        return root;
    }
};

