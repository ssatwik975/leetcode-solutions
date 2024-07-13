class Solution {
public:
    void flatten(TreeNode* root) {
        // Initialize a pointer
        // 'curr' to the root of the tree
        TreeNode* curr = root;

        // Iterate until 'curr'
        // becomes NULL
        while (curr) {
            // Check if the current
            // node has a left child
            if (curr->left) {
                // If yes, find the rightmost
                // node in the left subtree
                TreeNode* pre = curr->left;
                while (pre->right) {
                    pre = pre->right;
                }

                // Connect the rightmost node in
                // the left subtree to the current
               //  node's right child
                pre->right = curr->right;

                // Move the entire left subtree to the
                // right child of the current node
                curr->right = curr->left;

                // Set the left child of
                // the current node to NULL
                curr->left = NULL;
            }

            // Move to the next node
            // on the right side
            curr = curr->right;
        }
    }
};

