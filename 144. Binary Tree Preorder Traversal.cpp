class Solution {
public:
    vector<int> result;

    void preorder(TreeNode* root) {

        if (root == nullptr) {
            return;
        }

        result.push_back(root->val);
        preorder(root->left);
        preorder(root->right);
    }

    vector<int> preorderTraversal(TreeNode* root) {

        result.clear();
        preorder(root);

        return result;
    }
};

