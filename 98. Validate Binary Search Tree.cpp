class Solution {
public:
    bool isValid(TreeNode* root, long long low, long long high) {

        if (root == nullptr) {
            return true;
        }

        if (root->val <= low || root->val >= high) {
            return false;
        }

        return isValid(root->left, low, root->val) && isValid(root->right, root->val, high);
    }

    bool isValidBST(TreeNode* root) {

        return isValid(root, (long long)INT_MIN - 1, (long long)INT_MAX + 1);
    }
};

