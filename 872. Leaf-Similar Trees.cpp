class Solution {
public:
    vector<int> leaf1;
    vector<int> leaf2;

    void getLeaf(TreeNode* root, vector<int>& leaf) {

        if (root == nullptr) {
            return;
        }

        if (root->left == nullptr && root->right == nullptr) {
            leaf.push_back(root->val);
            return;
        }

        getLeaf(root->left, leaf);
        getLeaf(root->right, leaf);
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {

        leaf1.clear();
        leaf2.clear();

        getLeaf(root1, leaf1);
        getLeaf(root2, leaf2);

        return leaf1 == leaf2;
    }
};

