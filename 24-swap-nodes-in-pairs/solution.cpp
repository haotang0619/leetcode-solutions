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
    ListNode* swapPairs(ListNode* head) {
        ListNode* curr = head;
        ListNode* newHead = NULL;
        ListNode* prev = NULL;
        while(curr != NULL) {
            ListNode* currNode = curr;
            if(currNode->next != NULL) {
                curr = currNode->next->next;
                currNode->next->next = currNode;
                if(prev != NULL) prev->next = currNode->next;
                else newHead = currNode->next;
                currNode->next = NULL;
            } else {
                curr = NULL;
                if(prev != NULL) prev->next = currNode;
                else newHead = currNode;
            }
            prev = currNode;
        }
        return newHead;
    }
};
