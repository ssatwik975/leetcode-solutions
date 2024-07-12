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
    int countNodes(TreeNode* root) {
        if(root == NULL){
            return 0;
        }

        int lh = findleft(root);
        int rh = findright(root);

        if(lh == rh) return (1<<rh)-1;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }

    int findright(TreeNode* root){
        int hgt = 0;
        while(root){
            hgt++;
            root = root->right;
        }
        return hgt;
    }


    int findleft(TreeNode* root){
        int hgt = 0;
        while(root){
            hgt++;
            root = root->left;
        }
        return hgt;
    }
};
