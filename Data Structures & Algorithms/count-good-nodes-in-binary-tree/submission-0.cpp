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
    int count = 0;
public:
    int goodNodes(TreeNode* root) {
        count = 0;
        dfs(root, -101);
        return count;
    }

    void dfs(TreeNode* root, int largest) {
        if (!root) return;

        if (root->val >= largest) {
            count++;
        }
        dfs(root->left, max(largest, root->val));
        dfs(root->right, max(largest, root->val));
    }
};
