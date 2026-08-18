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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> st(nums.begin(), nums.end());
        ListNode *tmp = new ListNode(-1, head), *prev = tmp, *now = head;
        while(now != nullptr) {
            if(st.contains(now->val)) {
                prev->next = now->next;
            } else prev = now;
            now = now->next;
        }
        return tmp->next;
    }
};
