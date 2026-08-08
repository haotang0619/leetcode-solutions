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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* tmp = new ListNode(-1, head);
        ListNode* node = head;
        int sz = 0;
        while(node != nullptr) node = node->next, sz++;
        node = head;
        ListNode* prev = tmp;
        int i = 1;
        while(node != nullptr) {
            if(i == sz - n + 1) {
                prev->next = node->next;
                break;
            }
            prev = node, node = node->next, i++;
        }
        return tmp->next;
    }
};
