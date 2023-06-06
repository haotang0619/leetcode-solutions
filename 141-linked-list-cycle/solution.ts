/**
 * Definition for singly-linked list.
 * class ListNode {
 *     val: number
 *     next: ListNode | null
 *     constructor(val?: number, next?: ListNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.next = (next===undefined ? null : next)
 *     }
 * }
 */

function hasCycle(head: ListNode | null): boolean {
    if(head === null) return false;
    let pointer1 = head;
    let pointer2 = head;
    
    do {
        pointer1 = pointer1?.next;
        pointer2 = pointer2?.next?.next;
        if(!pointer1 || !pointer2) return false;
    } while(pointer1 !== pointer2)
        
    return true;
};
