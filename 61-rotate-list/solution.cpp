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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* node = head;
        int len = 0;
        while(node != NULL) {
            len++;
            node = node->next;
        }
        if(len == 0) return head;
        k = k % len;
        if(k == 0) return head;
        int x = len - k;
        node = head;
        while(--x) node = node->next;
        ListNode* newHead = node->next;
        node->next = NULL;
        node = newHead;
        while(node->next != NULL) node = node->next;
        node->next = head;
        return newHead;
    }
};
