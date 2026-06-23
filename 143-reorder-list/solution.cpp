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
    void reorderList(ListNode* head) {
        vector<ListNode*> v;
        ListNode* node = head;
        while(node != NULL) {
            v.push_back(node);
            node = node->next;
        }
        int n = v.size();
        int i = 0, cnt = 0, mode = 0;
        while(cnt < n) {
            if(mode == 0) {
                int j = n - 1 - i;
                if(i < j) v[i]->next = v[j];
                else v[i]->next = NULL;
                i = j;
            } else {
                int j = n - 1 - i + 1;
                if(i > j) v[i]->next = v[j];
                else v[i]->next = NULL;
                i = j;
            }
            cnt++;
            mode = 1 - mode;
        }
    }
};
