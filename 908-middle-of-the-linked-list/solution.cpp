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
    ListNode* middleNode(ListNode* head) {
        ListNode* node1 = head;
        ListNode* node2 = head->next;
        if(node2 == nullptr) return node1;
        while(node2 != nullptr) {
            node2 = node2->next;
            if(node2 == nullptr) break;
            node2 = node2->next;
            if(node2 == nullptr) break;
            node1 = node1->next;
        }
        return node1->next;
    }
};
