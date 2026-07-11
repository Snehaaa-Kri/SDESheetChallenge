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
    TreeNode* createBst(TreeNode* root, int el){
        if(root == nullptr){
            root = new TreeNode(el);
        }

        if(el > root->val){
            root->right = createBst(root->right, el);
        }
        else if(el < root->val){
            root->left = createBst(root->left, el);
        }
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root = new TreeNode(); 
        root = nullptr;
        for(int i=0; i<preorder.size(); i++){
            root = createBst(root, preorder[i]);
        }
        return root;
    }
};