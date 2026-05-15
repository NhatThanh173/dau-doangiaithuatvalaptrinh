class Solution {
public:
    vector<string> result;

    void dfs(TreeNode* root, string path) {

        if (root == nullptr) {
            return;
        }

        path += to_string(root->val);

        if (root->left == nullptr && root->right == nullptr) {
            result.push_back(path);
            return;
        }

        path += "->";
        dfs(root->left, path);
        dfs(root->right, path);
    }

    vector<string> binaryTreePaths(TreeNode* root) {

        result.clear();
        dfs(root, "");

        return result;
    }
};

