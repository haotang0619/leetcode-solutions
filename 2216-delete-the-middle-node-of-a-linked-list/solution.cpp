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
    ListNode* deleteMiddle(ListNode* head) {
        int n = 0;
        ListNode* node = head;
        while(node != NULL) n++, node = node->next;
        node = head;
        if(n == 1) return NULL;
        int idx = 0;
        while(idx < n / 2 - 1) {
            idx++;
            node = node->next;
        }
        ListNode* nextNext = node->next->next;
        node->next = nextNext;
        return head;
    }
};
