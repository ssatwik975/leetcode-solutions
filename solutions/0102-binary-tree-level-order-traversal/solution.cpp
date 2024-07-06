/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> lvls;
        if (root == NULL) return lvls;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            vector<int> lvl;
            int n = q.size();
            for (int i = 0; i < n; i++) {
                TreeNode* node = q.front();
                lvl.push_back(node->val);

                q.pop();

                if (node->left != NULL) q.push(node->left);
                if (node->right != NULL) q.push(node->right);
            }
            lvls.push_back(lvl);
        }
        return lvls;
    }
};
