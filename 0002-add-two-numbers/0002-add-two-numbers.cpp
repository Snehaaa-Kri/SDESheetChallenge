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
    ListNode* addTwoRevNumbs(ListNode* l1, ListNode* l2){
        ListNode* head = nullptr;
        ListNode* tail = nullptr;

        int carry = 0;
        while(l1 != nullptr || l2 != nullptr || carry>0){
            int sum = carry;

            if(l1 != nullptr) {
                sum += l1->val;
                l1 = l1->next;
            }
            if(l2 != nullptr) {
                sum += l2->val;
                l2 = l2->next;
            }
            //node value assign
            carry = sum/10;
            int data = sum%10;

            //node addition
            ListNode* newNode = new ListNode(data);
            if(head == nullptr) {
                head = tail = newNode;
            }
            else {
                tail->next = newNode;
                tail = newNode;
            }  
        }
        return head;
    }


    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return addTwoRevNumbs(l1, l2);
    }
};