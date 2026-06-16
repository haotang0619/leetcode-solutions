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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* newHead = head;
        ListNode* now = head->next;
        newHead->next = NULL;
        while(now != NULL) {
            ListNode* nextNow = now->next;
            ListNode* cursor = newHead;
            if(now->val <= cursor->val) {
                now->next = newHead;
                newHead = now;
            } else {
                ListNode* nextCursor = cursor->next;
                while(cursor->next != NULL && cursor->next->val < now->val) {
                    cursor = cursor->next;
                    nextCursor = cursor->next;
                }
                cursor->next = now;
                now->next = nextCursor;
            }
            now = nextNow;
        }
        return newHead;
    }
};
