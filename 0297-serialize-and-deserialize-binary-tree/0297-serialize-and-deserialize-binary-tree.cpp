/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // Encodes a tree to a single string. - using level order traversal
    string serialize(TreeNode* root) {
        if(root == nullptr) return ""; 

        string str;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int size = q.size();
            while(size--){
                TreeNode* node = q.front();
                q.pop();

                if(node == nullptr){
                    str += "#,";
                    continue;
                }
                str +=  to_string(node->val)+",";



                q.push(node->left);
                q.push(node->right);
            }
        }
        cout << "str: "<< str<<endl;
        return str;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty()) return nullptr;
     
        stringstream ss(data);
        string val;

        getline(ss, val, ',');
        TreeNode* root = val=="#"? nullptr : new TreeNode(stoi(val));


        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* node = q.front(); q.pop();

            //left
            if(getline(ss, val, ',')){
                if(val != "#"){
                    node->left = new TreeNode(stoi(val));
                    q.push(node->left);
                }
            }

            //right
            if(getline(ss, val, ',')){
                if(val != "#"){
                    node->right = new TreeNode(stoi(val));
                    q.push(node->right);
                }
            }
        }
        return root;    
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));