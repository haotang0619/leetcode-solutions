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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left == right) return head;
        ListNode* tmp = new ListNode(0, head);
        ListNode* begin = tmp;
        ListNode* prev = tmp;
        ListNode* node = head;
        ListNode* tail;
        int cnt = 1;
        while(node != NULL) {
            if(cnt < left) {
                begin = prev = node;
                node = node->next;
            } else if(cnt == left) {
                tail = prev = node;
                node = node->next;
            } else if(cnt == right) {
                begin->next = node;
                tail->next = node->next;
                node->next = prev;
                break;
            } else {
                ListNode* nextNode = node->next;
                node->next = prev;
                prev = node;
                node = nextNode;
            }
            cnt++;
        }
        return tmp->next;
    }
};
