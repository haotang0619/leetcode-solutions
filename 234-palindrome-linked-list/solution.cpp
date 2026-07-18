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
    bool isPalindrome(ListNode* head) {
        int n = 0;
        ListNode* node = head;
        while(node != nullptr) n++, node = node->next;
        int half = n / 2 + n % 2;
        ListNode* prev = nullptr;
        node = head;
        for(int i = 0; i < n; i++) {
            if(i >= half) {
                ListNode* next = node->next;
                node->next = prev;
                prev = node;
                node = next;
            } else node = node->next;
        }
        node = head;
        for(int i = 0; i < n / 2; i++) {
            if(node->val != prev->val) return false;
            node = node->next, prev = prev->next;
        }
        return true;
    }
};
