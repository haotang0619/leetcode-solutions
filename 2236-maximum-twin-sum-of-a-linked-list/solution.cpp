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
    int pairSum(ListNode* head) {
        int n = 0;
        ListNode* node = head;
        while(node != NULL) n++, node = node->next;
        node = head;
        vector<int> v(n / 2);
        int ans = 0;
        for(int i = 0; i < n; i++) {
            if(i < n / 2) v[i] = node->val;
            else ans = max(ans, v[n - 1 - i] + node->val);
            node = node->next;
        }
        return ans;
    }
};
