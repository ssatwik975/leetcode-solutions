class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        map<int, map<int, multiset<int>>> nodes; // vertical, level and elements
        queue<pair<TreeNode*, pair<int,int>>> q;
        q.push({root, {0,0}}); //root node and its coordinates;
        
        while(!q.empty()){
            auto swag = q.front();
            q.pop();

            TreeNode* k = swag.first;
            int x = swag.second.first;
            int y = swag.second.second;

            nodes[x][y].insert(k->val);

            if(k->left) q.push({k->left, {x - 1, y + 1}});
            if(k->right) q.push({k->right, {x + 1, y + 1}});

        }

        vector<vector<int>>ans;
        for(auto i : nodes){
            vector<int>vert;
            for(auto j : i.second){
                vert.insert(vert.end(), j.second.begin(), j.second.end());
            }
            ans.push_back(vert);
        }
        return ans;
    }
};




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

 //had it not been for the sorting I wouldve used number of rights
