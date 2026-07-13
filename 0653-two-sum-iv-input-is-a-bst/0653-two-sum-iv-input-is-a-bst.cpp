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

class BSTIterator{
    stack<TreeNode*> mystack;
    //reverse=true ? will give before elements
    //reverse = false? will give next element in increasing order of elements
    bool rev = true;

    public:
        BSTIterator(TreeNode* root, bool isRev){
            rev = isRev;
            pushAll(root);
        }

        bool hasNext(){
            return !mystack.empty();
        }

        int next(){
            TreeNode* temp = mystack.top();
            mystack.pop();

            if(!rev) pushAll(temp->right);
            else pushAll(temp->left);

            return temp->val;
        }
    private:
        void pushAll(TreeNode* node){
            for(; node != nullptr; ){
                mystack.push(node);

                if(rev) node = node->right;
                else node = node->left;
            }
        }

};
class Solution {
public:

//optimal approach - using BST Iterator TC - O(N)  and SC = O(2H)   -- not done


    void getInorder(TreeNode* root, vector<int> &in){
        if(root == nullptr) return;

        getInorder(root->left, in);
        in.push_back(root->val);
        getInorder(root->right, in);
    }
    bool findTarget_storage(TreeNode* root, int k) {
        //inorder traversal + 2 sum problem  -- O(N+N) 
        //inorder will always be in sorted order

        vector<int> in;
        getInorder(root, in);
        if(in.size() < 2) return false;

        int s = 0;
        int e = in.size()-1;

        while(s<e){
            int sum = in[s]+in[e];
            
            if(sum == k) return true;
            else if(sum < k) s++;
            else e--;
        }
        return false;
    }
    bool findTarget(TreeNode* root, int k) {
        if(root == nullptr) return false;

        BSTIterator l(root, false);
        BSTIterator r(root, true);

        int i=l.next();
        int j=r.next();
        while(i<j){
            int sum = i+j;
            if(sum == k) return true;
            else if(sum < k) i = l.next();
            else j = r.next();
        }
        return false;
    }
};