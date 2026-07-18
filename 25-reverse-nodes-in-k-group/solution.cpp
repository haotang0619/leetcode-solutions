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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k == 1) return head;
        ListNode *tmp = new ListNode(-1, head);
        ListNode *prevHead = tmp, *l = head, *r = head;
        int cnt = 1;
        while(r != nullptr) {
            if(cnt == k) {
                ListNode *prev = nullptr, *origL = l, *nextHead = r->next;
                r->next = nullptr;
                while(l != nullptr) {
                    ListNode *next = l->next;
                    l->next = prev;
                    prev = l;
                    l = next;
                }
                prevHead->next = prev;
                origL->next = nextHead;
                cnt = 1, prevHead = origL, l = r = nextHead;
            } else cnt++, r = r->next;
        }
        return tmp->next;
    }
};
