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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == nullptr) return list2;
        if(list2 == nullptr) return list1;

        ListNode* temp1 = list1;
        ListNode* temp2 = list2;

        //head and tail initialization
        ListNode* head = nullptr;
        if(temp1->val <= temp2->val){
            head = temp1;
            temp1 = temp1->next;
        } 
        else{
            head = temp2;
            temp2 = temp2->next;
        }

        ListNode* tail = head;


        while(temp1 && temp2){
            if(temp1->val <= temp2->val){
                tail->next = temp1;
                tail = tail->next;
                temp1 = temp1->next;
            }
            else{
                tail->next = temp2;
                tail = tail->next;
                temp2 = temp2->next;
            }
        }

        while(temp1){
            tail->next = temp1;
            temp1 = temp1->next;
            tail = tail->next;
        }

        while(temp2){
            tail->next = temp2;
            temp2 = temp2->next;
            tail = tail->next;
        }
        return head;
    }
};