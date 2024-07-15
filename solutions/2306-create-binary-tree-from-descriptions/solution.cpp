class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> nodeMap;  // Map to store nodes by their values
        unordered_map<int, bool> isChild;       // Map to track which nodes are children
        
        // Go through each description
        for (auto& desc : descriptions) {
            int parentVal = desc[0];
            int childVal = desc[1];
            int isLeft = desc[2];

            // If parent node is not in the map, create it and add it to the map
            if (nodeMap.find(parentVal) == nodeMap.end()) {
                nodeMap[parentVal] = new TreeNode(parentVal);
            }

            // If child node is not in the map, create it and add it to the map
            if (nodeMap.find(childVal) == nodeMap.end()) {
                nodeMap[childVal] = new TreeNode(childVal);
            }

            // Attach the child to the parent based on the direction
            if (isLeft) {
                nodeMap[parentVal]->left = nodeMap[childVal];
            } else {
                nodeMap[parentVal]->right = nodeMap[childVal];
            }

            // Mark the child node
            isChild[childVal] = true;
        }

        // Find the root of the tree
        TreeNode* root = nullptr;
        for (auto& nodePair : nodeMap) {
            if (isChild.find(nodePair.first) == isChild.end()) {
                root = nodePair.second;
                break;
            }
        }

        // Return the root node
        return root;
    }
};
