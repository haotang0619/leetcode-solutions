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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* root = NULL;
        ListNode* prev;
        int carry = 0;
        while(l1 != NULL || l2 != NULL) {
            ListNode* node = new ListNode();
            int sum;
            if(l1 == NULL) sum = l2->val + carry;
            else if(l2 == NULL) sum = l1->val + carry;
            else sum = l1->val + l2->val + carry;
            node->val = sum % 10;
            carry = sum / 10;
            if(root == NULL) root = node;
            else prev->next = node;
            prev = node;
            if(l1 != NULL) l1 = l1->next;
            if(l2 != NULL) l2 = l2->next;
        }
        if(carry > 0) {
            ListNode* node = new ListNode(carry);
            prev->next = node;
        }
        return root;
    }
};
