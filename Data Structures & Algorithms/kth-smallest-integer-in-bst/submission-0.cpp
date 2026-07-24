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
    int count;
    int ans;
public:
    int kthSmallest(TreeNode* root, int k) {
        count = 0;
        ans = -1;
        inorder(root, k);
        return ans;
    }

    void inorder(TreeNode* node, int k) {
        if (!node) return;
        inorder(node->left, k);
        if (ans >= 0) return;
        count++;
        if (count == k) {
            ans = node->val;
            return;
        }
        inorder(node->right, k);
    }
};
