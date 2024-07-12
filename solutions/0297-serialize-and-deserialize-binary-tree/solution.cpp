/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == NULL) return "#";
        string data;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (node) {
                data += to_string(node->val) + ",";
                q.push(node->left);
                q.push(node->right);
            } else {
                data += "#,";
            }
        }
        data.pop_back();  // Remove the trailing comma
        return data;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data == "#") return NULL;
        
        stringstream s(data);
        string str;
        getline(s, str, ',');
        
        TreeNode* root = new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            
            if (getline(s, str, ',')) {
                if (str != "#") {
                    TreeNode* leftNode = new TreeNode(stoi(str));
                    node->left = leftNode;
                    q.push(leftNode);
                }
            }
            
            if (getline(s, str, ',')) {
                if (str != "#") {
                    TreeNode* rightNode = new TreeNode(stoi(str));
                    node->right = rightNode;
                    q.push(rightNode);
                }
            }
        }
        
        return root;
    }
};


