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
    ListNode* partition(ListNode* head, int x) {
        if(head == NULL) return head;
        ListNode* root = new ListNode();
        root->next = head;
        ListNode* tail = head;
        while(tail->next != NULL) tail = tail->next;
        ListNode* original_tail = tail;
        
        ListNode* node = root->next;
        ListNode* prev = root;
        while(node != original_tail) {
            if(node->val >= x) {
                prev->next = node->next;
                tail->next = node;
                tail = node;
                node->next = NULL;
                node = prev->next;
            } else {
                prev = node;
                node = node->next;
            }
        }
        if(node->val >= x && node != tail) {
            prev->next = node->next;
            tail->next = node;
            node->next = NULL;
        }
        return root->next;
    }
};
