class Solution {
public:
    TreeNode* buildTreeHelper(vector<int>& preorder, int preLeft, int preRight,
        vector<int>& inorder, int inLeft, int inRight,
        unordered_map<int, int>& pos) {

        if (preLeft > preRight || inLeft > inRight) {
            return nullptr;
        }

        int rootVal = preorder[preLeft];
        TreeNode* root = new TreeNode(rootVal);

        int mid = pos[rootVal];
        int leftSize = mid - inLeft;

        root->left = buildTreeHelper(preorder, preLeft + 1, preLeft + leftSize,
            inorder, inLeft, mid - 1, pos);

        root->right = buildTreeHelper(preorder, preLeft + leftSize + 1, preRight,
            inorder, mid + 1, inRight, pos);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        unordered_map<int, int> pos;
        for (int i = 0; i < inorder.size(); i++) {
            pos[inorder[i]] = i;
        }

        return buildTreeHelper(preorder, 0, preorder.size() - 1,
            inorder, 0, inorder.size() - 1, pos);
    }
};

