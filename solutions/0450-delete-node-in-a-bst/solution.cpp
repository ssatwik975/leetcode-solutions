class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val, TreeNode*& prev) {
        if (root == NULL)
            return NULL;
        if ((root->left != NULL && root->left->val == val) ||
            (root->right != NULL && root->right->val == val))
            prev = root;
        if (root->val == val)
            return root;
        else if (root->val > val) {
            return searchBST(root->left, val, prev);
        } else {
            return searchBST(root->right, val, prev);
        }
        return NULL;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == NULL)
            return NULL;

        TreeNode* prev = nullptr;
        TreeNode* del = searchBST(root, key, prev);
        if (del == NULL)
            return root; // Node not found

        TreeNode* lh = del->left;
        TreeNode* rh = del->right;

        if (lh) {
            TreeNode* rightmost = lh;
            while (rightmost->right) {
                rightmost = rightmost->right;
            }
            rightmost->right = rh;
        } else {
            lh = rh;
        }

        if (prev == NULL) { // Deleting the root node
            root = lh;
        } else {
            if (prev->left == del) {
                prev->left = lh;
            } else {
                prev->right = lh;
            }
        }
        return root;
    }
};

