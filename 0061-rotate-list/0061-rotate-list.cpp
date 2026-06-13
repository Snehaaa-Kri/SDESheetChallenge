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
    int getn(ListNode* head){
        if(head == nullptr) return 0;
        int cnt = 0;

        ListNode* temp = head;

        while(temp != nullptr){
            cnt++;
            temp = temp->next;
        }
        return cnt;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        int n = getn(head);
        if(n>0) k = k%n;
        if(head == nullptr || head->next == nullptr || k==0) return head; //empty LL or single node LL

        ListNode* prev = nullptr;
        ListNode* next = head;
        int cnt = n-k;

        while(cnt-->0){
            prev = next;
            next = next->next;
        }

        prev->next = nullptr;
        ListNode* temp = next;
        while(temp->next != nullptr){
            temp = temp->next;
        }

        temp->next = head;

        return next;
    }
};