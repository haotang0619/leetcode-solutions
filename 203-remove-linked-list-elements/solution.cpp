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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *tmp = new ListNode(0, head);
        ListNode *node = head, *prev = tmp;
        while(node != nullptr) {
            if(node->val == val) prev->next = node->next;
            else prev = node;
            node = node->next;
        }
        return tmp->next;
    }
};
