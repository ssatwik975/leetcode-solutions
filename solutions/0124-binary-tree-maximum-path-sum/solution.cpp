class Solution {
public:
    int tillm(TreeNode* root, int& ans) {
        if (!root)
            return 0;
        int a = tillm(root->left, ans);
        int b = tillm(root->right, ans);
        if (a < 0)
            a = 0;
        if (b < 0)
            b = 0;
        if (a + b + root->val > ans)
            ans = a + b + root->val;
        return root->val += max(a,b);
    }
    int maxPathSum(TreeNode* root) {
        int ans = -2147483648;
        tillm(root, ans);
        return ans;
    }
};
