/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    bool isBalancedTree;

    bool isBalanced(TreeNode* root) {
        isBalancedTree = true;
        maxDepth(root);
        return isBalancedTree;
    }

    int maxDepth(TreeNode* root) {
        if (root == nullptr) return 0;

        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);

        if (abs(leftDepth - rightDepth) > 1) {
            isBalancedTree = false;
        }

        return max(leftDepth, rightDepth) + 1;
    }
};
