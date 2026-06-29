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
    ListNode* mergeSort(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;   
        
        ListNode* node1 = head;
        ListNode* node2 = head;
        while(node2 != nullptr) {
            node2 = node2->next;
            if(node2 == nullptr) break;
            node2 = node2->next;
            if(node2 == nullptr) break;
            node1 = node1->next;
        }
        ListNode* mid = node1->next;
        node1->next = nullptr;
        ListNode* lHead = mergeSort(head);
        ListNode* rHead = mergeSort(mid);
        
        ListNode* newHead = new ListNode;
        ListNode* newNode = newHead;
        
        while(lHead != nullptr && rHead != nullptr) {
            ListNode* next;
            if(lHead->val <= rHead->val) {
                newNode->next = lHead;
                lHead = lHead->next;
            } else {
                newNode->next = rHead;
                rHead = rHead->next;
            }
            newNode = newNode->next;
        }
        while(lHead != nullptr) {
            newNode->next = lHead;
            lHead = lHead->next;
            newNode = newNode->next;
        }
        while(rHead != nullptr) {
            newNode->next = rHead;
            rHead = rHead->next;
            newNode = newNode->next;
        }
        newNode->next = nullptr;
        return newHead->next;
    }

    ListNode* sortList(ListNode* head) {
        return mergeSort(head);
    }
};
