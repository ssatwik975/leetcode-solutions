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
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        // Two null trees are flip equivalent
        // A non-null and null tree are NOT flip equivalent
        // Two non-null trees with different root values are NOT flip equivalent
        // Two non-null trees are flip equivalent if
        //      The left subtree of tree1 is flip equivalent with the left subtree of tree2 and the right subtree of tree1 is   
        //      flipequivalent with the right subtree of tree2 (no flip case)
        //      OR
        //      The right subtree of tree1 is flip equivalent with the left subtree of tree2 and the left subtree of tree1 is
        //      flipequivalent with the right subtree of tree2 (flip case)
        if ( !root1 && !root2 ) return true;
        if ( !root1 && root2 || root1 &&!root2 || root1->val != root2->val ) return false;
        return flipEquiv( root1->left, root2->left ) && flipEquiv( root1->right, root2->right )
            || flipEquiv( root1->right, root2->left ) && flipEquiv( root1->left, root2->right );
    }
};
