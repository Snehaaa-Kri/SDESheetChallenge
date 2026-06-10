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
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int sz=0;

        ListNode* temp = head;
        while(temp != nullptr){
            sz++;
            temp = temp->next;
        }
        
        if(sz == n) return head->next;


        ListNode* prev = nullptr;
        temp = head;
        int k = 0;

        while(k < sz-n){
            k++;
            prev = temp;
            temp = temp->next;
        }

        if(temp != nullptr){
            prev->next = temp->next;
            temp->next = nullptr;
        }
        else prev->next = nullptr;
        
        return head;
    }
};