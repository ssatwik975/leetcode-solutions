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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};
        queue<TreeNode*>q;
        q.push(root);
        vector<vector<int>>ds;
        bool flag = true;
        while(!q.empty()){
            int size = q.size();
            vector<int>lvl(size);
            for(int i = 0; i < size; i++){
                TreeNode* k = q.front();
                q.pop();
                if(!k) continue;
                int index = flag? i : size - 1 - i;
                if(k->left) q.push(k->left);
                if(k->right) q.push(k->right);
                lvl[index] = k->val;
                
            }
            ds.push_back(lvl);
            flag = !flag;
        }
        return ds;
    }
};
