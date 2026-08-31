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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> ans;
        int cnt = 2;

        if (head->next->next == NULL)
            return {-1, -1};

        ListNode* prev = head;
        ListNode* curr = head->next;
        ListNode* next1 = curr->next;

        while (next1 != NULL) {
            if ((curr->val > prev->val and curr->val > next1->val) ||
                (curr->val < prev->val and curr->val < next1->val)) {
                ans.push_back(cnt);
            }

            cnt++;
            prev = prev->next;
            curr = curr->next;
            next1 = next1->next;
        }

        sort(ans.begin(), ans.end());

        int mini = INT_MAX;

        if (ans.size() <= 1)
            return {-1, -1};

        for (auto i = 0; i < ans.size() - 1; i++) {
            mini = min(mini, ans[i + 1] - ans[i]);
            cout << ans[i] << " ";
        }

        return {mini, ans[ans.size() - 1] - ans[0]};
    }
};