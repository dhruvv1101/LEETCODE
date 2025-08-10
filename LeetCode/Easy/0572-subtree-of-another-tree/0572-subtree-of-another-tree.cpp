class Solution {
public:
    bool isSubtree(TreeNode* root, TreeNode* subroot) {
        if (!root) return false;
        if (isSame(root, subroot)) return true;
        return isSubtree(root->left, subroot) || isSubtree(root->right, subroot);
    }

private:
    bool isSame(TreeNode* a, TreeNode* b) {
        if (!a && !b) return true;
        if (!a || !b) return false;
        if (a->val != b->val) return false;
        return isSame(a->left, b->left) && isSame(a->right, b->right);
    }
};
