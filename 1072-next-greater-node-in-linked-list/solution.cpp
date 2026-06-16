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
    vector<int> nextLargerNodes(ListNode* head) {
        stack<pair<int, int>> sk;
        ListNode* now = head;
        vector<int> ans;
        int idx = 0;
        while(now != NULL) {
            while(!sk.empty() && sk.top().first < now->val) {
                auto [val, i] = sk.top();
                sk.pop();
                while(i >= ans.size()) ans.push_back(0);
                ans[i] = now->val;
            }
            sk.push({now->val, idx});
            idx++;
            now = now->next;
        }
        while(!sk.empty()) {
            auto [val, i] = sk.top();
            sk.pop();
            while(i >= ans.size()) ans.push_back(0);
        }
        return ans;
    }
};
