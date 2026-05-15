class Solution {
public:
    bool findTarget(TreeNode* root, int k) {

        if (root == nullptr) {
            return false;
        }

        unordered_set<int> seen;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            int canFind = k - node->val;
            if (seen.count(canFind)) {
                return true;
            }

            seen.insert(node->val);

            if (node->left != nullptr) {
                q.push(node->left);
            }
            if (node->right != nullptr) {
                q.push(node->right);
            }
        }

        return false;
    }
};

