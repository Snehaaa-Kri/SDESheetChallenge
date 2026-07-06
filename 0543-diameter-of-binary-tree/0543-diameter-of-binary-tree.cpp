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
    int maxdia;
    int height(TreeNode* root){
        if(root == nullptr) return 0;

        int lh = height(root->left);
        int rh = height(root->right);

        maxdia = max(maxdia, lh+rh);

        return 1+max(lh, rh);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == nullptr) return 0;
        maxdia = 0;
        int h = height(root);
        return maxdia;
    }
};