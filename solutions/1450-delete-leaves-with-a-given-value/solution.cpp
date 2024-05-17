
TreeNode *dfs(TreeNode *n, int target) {
    bool leaf = true;
    if (n->left && (n->left = dfs(n->left, target))) leaf = false;
    if (n->right && (n->right = dfs(n->right, target))) leaf = false;
    return leaf && n->val == target ? nullptr : n;
}

class Solution {
public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        return dfs(root, target);
    }
};
