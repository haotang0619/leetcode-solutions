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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* root = NULL;
        ListNode* prev = NULL;

        while(list1 != NULL || list2 != NULL) {
            ListNode* node;
            if(list1 == NULL) {
                node = list2;
                list2 = list2->next;
            } else if(list2 == NULL) {
                node = list1;
                list1 = list1->next;
            } else if(list1->val <= list2->val) {
                node = list1;
                list1 = list1->next;
            } else {
                node = list2;
                list2 = list2->next;
            }
            if(root == NULL) root = node;
            else prev->next = node;
            prev = node;
        }
        return root;
    }
};
