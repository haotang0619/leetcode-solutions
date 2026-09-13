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
        int i1 = -1, i2 = -1, idx = 0, prev = head->val;
        vector<int> ans = {INT_MAX, -1};
        ListNode* node = head->next;
        while(node->next != nullptr) {
            int next = node->next->val, now = node->val;
            if(prev < now && now > next || prev > now && now < next) {
                if(i1 == -1) i1 = idx;
                else ans[1] = max(ans[1], idx - i1);
                if(i2 != -1) ans[0] = min(ans[0], idx - i2);
                i2 = idx;
            }
            ++idx, prev = node->val, node = node->next;
        }
        if(ans[0] == INT_MAX) return {-1, -1};
        return ans;
    }
};
