class Solution {
public:
    bool check(TreeNode* root, int value) {

        if (root == nullptr) {
            return true;
        }

        if (root->val != value) {
            return false;
        }

        return check(root->left, value) && check(root->right, value);
    }

    bool isUnivalTree(TreeNode* root) {

        if (root == nullptr) {
            return true;
        }

        return check(root, root->val);
    }
};

