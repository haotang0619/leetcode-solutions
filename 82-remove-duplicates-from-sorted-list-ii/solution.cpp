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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* root = new ListNode(INT_MIN, head);
        ListNode* prev = root;
        ListNode* node = root->next;
        while(node != NULL) {
            while(node != NULL && node->next != NULL && node->val == node->next->val){
                int v = node->val;
                while(node != NULL && node->val == v) node = node->next;
            }
            prev->next = node;
            prev = node;
            if(node != NULL) node = node->next;
        }
        return root->next;
    }
};
