class Solution {
public:
    TreeNode* newRoot = nullptr;
    TreeNode* current = nullptr;

    void inorder(TreeNode* root) {

        if (root == nullptr) {
            return;
        }

        inorder(root->left);

        root->left = nullptr;
        if (newRoot == nullptr) {
            newRoot = root;
            current = root;
        } else {
            current->right = root;
            current = root;
        }

        inorder(root->right);
    }

    TreeNode* increasingBST(TreeNode* root) {

        newRoot = nullptr;
        current = nullptr;

        inorder(root);
        return newRoot;
    }
};

