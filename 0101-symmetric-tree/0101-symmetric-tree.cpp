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
    bool isSym(TreeNode* leftPtr, TreeNode* rightPtr){
        if(leftPtr == nullptr && rightPtr == nullptr) return true;
        if((leftPtr == nullptr && rightPtr != nullptr) || (leftPtr != nullptr && rightPtr == nullptr)) return false;
        if(leftPtr->val != rightPtr->val) return false;
        bool leftans = isSym(leftPtr->left, rightPtr->right);
        bool rightans = isSym(leftPtr->right, rightPtr->left);
        return (leftans && rightans);
    }
    bool isSymmetric(TreeNode* root) {
        TreeNode* leftPtr = root;
        TreeNode* rightPtr = root;
        return isSym(leftPtr, rightPtr);
    }
};