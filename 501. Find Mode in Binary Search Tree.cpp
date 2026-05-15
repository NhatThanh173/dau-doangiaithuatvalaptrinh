class Solution {
public:
    TreeNode* prev = nullptr;
    int currentCount = 0;
    int maxCount = 0;
    vector<int> result;

    void inorder(TreeNode* root) {

        if (root == nullptr) {
            return;
        }

        inorder(root->left);

        if (prev != nullptr && prev->val == root->val) {
            currentCount++;
        } else {
            currentCount = 1;
        }

        if (currentCount > maxCount) {
            maxCount = currentCount;
            result.clear();
            result.push_back(root->val);
        } else if (currentCount == maxCount) {
            result.push_back(root->val);
        }

        prev = root;

        inorder(root->right);
    }

    vector<int> findMode(TreeNode* root) {

        prev = nullptr;
        currentCount = 0;
        maxCount = 0;
        result.clear();

        inorder(root);
        return result;
    }
};

