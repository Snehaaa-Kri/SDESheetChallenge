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



    ListNode* reverseFunction(ListNode* head){
        if(head == nullptr || head->next == nullptr) return head;  //empty or single linked list reversal = same

        ListNode* prev = nullptr;
        ListNode* curr = head;

        while(curr != nullptr){
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    ListNode* findKthNode(ListNode* temp, int k){
        ListNode* kthNode = temp;
        for(int i=1; i<k; i++){   //find kth should run k-1  times!!!!
            if(kthNode == nullptr) return nullptr;
            kthNode = kthNode->next;
        }
        return kthNode;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* nextNode = nullptr;
        ListNode* prevNode = nullptr;

        while(temp != nullptr){
            //1. find kth node
            ListNode* kthNode = findKthNode(temp, k);

            //2. check is it the last group of size < k?
            if(kthNode == nullptr) {
                if(prevNode) prevNode->next = temp;
                break;
            }

            //3.if kth node exists
            nextNode = kthNode->next;           //preserve next node
            kthNode->next = nullptr;
            ListNode* newNode = reverseFunction(temp);  //new node is same as kth node
            if(temp == head) head = kthNode;
            else {
                prevNode->next = kthNode;
            }

            prevNode = temp;
            temp = nextNode;
        }
        return head;
    }
};