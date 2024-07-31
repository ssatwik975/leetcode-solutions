class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;

        // Using unsigned long long for indices to handle large values safely
        using ULL = unsigned long long;

        queue<pair<TreeNode*, ULL>> q;
        q.push({root, 0}); // Initialize with root at index 0

        ULL maxWidth = 0;

        while (!q.empty()) {
            int size = q.size();
            ULL minIndex = q.front().second; // Index of the leftmost node at the current level
            ULL firstIndex, lastIndex;

            for (int i = 0; i < size; i++) {
                auto [node, index] = q.front();
                q.pop();

                // Normalize index by subtracting minIndex to keep it starting from 0
                index -= minIndex;

                if (i == 0) firstIndex = index;
                if (i == size - 1) lastIndex = index;

                if (node->left) q.push({node->left, 2 * index + 1});
                if (node->right) q.push({node->right, 2 * index + 2});
            }

            // Calculate the width of the current level
            maxWidth = std::max(maxWidth, lastIndex - firstIndex + 1);
        }

        return maxWidth;
    }
};
