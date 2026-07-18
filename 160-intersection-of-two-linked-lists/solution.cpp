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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *nodeA = headA, *nodeB = headB;
        bool flagA = false, flagB = false;
        while(nodeA != nodeB) {
            nodeA = nodeA->next;
            nodeB = nodeB->next;
            if(nodeA == nullptr) {
                if(flagA) return nullptr;
                flagA = true, nodeA = headB;
            }
            if(nodeB == nullptr) {
                if(flagB) return nullptr;
                flagB = true, nodeB = headA;
            }
        }
        return nodeA;
    }
};
