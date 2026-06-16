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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL) return NULL;
        ListNode* oddHead = NULL;
        ListNode* oddNow = NULL;
        ListNode* evenHead = NULL;
        ListNode* evenNow = NULL;
        ListNode* now = head;
        int idx = 1;
        while(now != NULL) {
            if(idx == 1) {
                oddHead = now; oddNow = now;
            } else if(idx == 2) {
                evenHead = now; evenNow = now;
            } else if(idx % 2 == 1) {
                oddNow->next = now; oddNow = now;
            } else {
                evenNow->next = now; evenNow = now;
            }
            now = now->next;
            idx++;
        }
        oddNow->next = evenHead;
        if(evenNow != NULL) evenNow->next = NULL; // IMPORTANT!!!
        return oddHead;
    }
};
