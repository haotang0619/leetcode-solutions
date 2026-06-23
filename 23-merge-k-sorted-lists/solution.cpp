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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        ListNode* head = NULL;
        ListNode* prev = NULL;
        while(true) {
            int minVal = INT_MAX, minIdx = -1;
            for(int i = 0; i < n; i++) {
                if(lists[i] != NULL && lists[i]->val < minVal) {
                    minVal = lists[i]->val;
                    minIdx = i;
                }
            }
            if(minIdx == -1) break;
            ListNode* node = new ListNode(minVal);
            if(head == NULL) head = node;
            if(prev != NULL) prev->next = node;
            lists[minIdx] = lists[minIdx]->next;
            prev = node;
        }
        return head;
    }
};
