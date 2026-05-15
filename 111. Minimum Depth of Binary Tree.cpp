class Solution {
public:
    int minDepth(TreeNode* root) {

        if (root == nullptr) {
            return 0;
        }

        // chỉ có right
        if (root->left == nullptr) {
            return 1 + minDepth(root->right);
        }

        // chỉ có left
        if (root->right == nullptr) {
            return 1 + minDepth(root->left);
        }

        // có cả 2
        return 1 + min(
            minDepth(root->left),
            minDepth(root->right)
        );
    }
};