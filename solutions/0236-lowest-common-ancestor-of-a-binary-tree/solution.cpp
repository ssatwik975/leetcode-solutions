/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool finder(TreeNode*root, TreeNode* target1, TreeNode* target2, TreeNode* &found){
        if(!root) return false;
        bool tgt = (root == target1 || root == target2);
        bool lh = finder(root->left, target1, target2, found);
        bool rh = finder(root->right, target1, target2, found);
        if((lh && rh) || (tgt && (lh || rh))){
            found = root;
        }
        
        return  lh || rh || tgt;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* found = new TreeNode;
        finder(root, p, q, found);
        return found;
    }
};
