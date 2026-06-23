/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class compare{
    public:
    bool operator()(ListNode* a, ListNode* b){
        return a->val > b->val;
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        //min heap
        priority_queue<ListNode*, vector<ListNode*>, compare> pq;

        for(ListNode* el: lists){ 
            if(el != nullptr) pq.push(el); 
        }

        ListNode* head = nullptr;
        ListNode* curr = head;
        while(!pq.empty()){
            ListNode* temp = pq.top();
            pq.pop();


            if(head == nullptr) {
                head = temp;
                curr = head;
            }
            else{
                curr->next = temp;
                curr = curr->next;
            }

            temp = temp->next;

            if(temp != nullptr){
                pq.push(temp);
            }
        }

        return head;
    }
};