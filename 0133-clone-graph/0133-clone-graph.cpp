/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node == nullptr) return node;

        unordered_map<Node*, Node*> mp; //old node , new node

        Node* newnode = new Node(node->val);
        mp[node] = newnode;

        //bfs
        queue<Node*> q;
        q.push(node);

        while(!q.empty()){
            Node* actualnode = q.front();
            q.pop();

            for(auto nebr: actualnode->neighbors){
               
                if(!mp.count(nebr)) {
                    mp[nebr] = new Node(nebr->val);
                    q.push(nebr);
                }

                mp[actualnode]->neighbors.push_back(mp[nebr]);
            }
        }
        return newnode;
    }
};