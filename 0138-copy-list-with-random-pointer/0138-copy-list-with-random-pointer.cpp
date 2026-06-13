/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == nullptr) return head;

        unordered_map<Node*, Node*> mp; //Original Node, deep copied node
        Node* temp = head;

        while(temp != nullptr){//O(N)
            Node* copynode = new Node(temp->val);
            mp[temp] = copynode;
            temp = temp->next;
        }

        temp = head;
        while(temp != nullptr){
            mp[temp]->next = mp[temp->next];
            mp[temp]->random = mp[temp->random];
            temp = temp->next;
        }

        return mp[head];
    }
};