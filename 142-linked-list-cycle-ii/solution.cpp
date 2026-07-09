/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == nullptr) return nullptr;
        ListNode *node1 = head, *node2 = head;
        while(node2 != nullptr) {
            node2 = node2->next;
            if(node2 == nullptr) break;
            node2 = node2->next;
            node1 = node1->next;
            if(node1 == node2) {
                node1 = head;
                while(node1 != node2) node1 = node1->next, node2 = node2->next;
                return node1;
            }
        }
        return nullptr;
    }
};
