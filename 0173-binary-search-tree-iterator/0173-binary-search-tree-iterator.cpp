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
class BSTIterator {
public:

    void getInorder(TreeNode* root, vector<TreeNode*> &in){
        if(root == nullptr) return;

        getInorder(root->left, in);
        in.push_back(root);
        getInorder(root->right, in);
    }

    vector<TreeNode*> in;
    int idx = -1;
    int n =0;


    BSTIterator(TreeNode* root) {
        getInorder(root, in);
        n = in.size();
    }
    
    int next() {
        idx++;
        if(idx<n){
            return in[idx]->val;
        }
        return -1; 
    }
    
    bool hasNext() {
        return (idx<n-1);
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */