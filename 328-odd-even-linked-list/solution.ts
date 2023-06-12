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

function oddEvenList(head: ListNode | null): ListNode | null {
  if (!head) return head;

  let now = head;
  let evenHead: ListNode | null = null;
  let evenNow: ListNode | null = null;
  while (true) {
    if (!evenHead) evenHead = now.next;
    if (evenNow !== null) evenNow.next = now.next;
    evenNow = now.next;
    now.next = now?.next?.next || null;
    if (evenNow !== null) evenNow.next = null;
    if (now.next === null) {
      now.next = evenHead;
      break;
    }
    now = now.next;
  }

  return head;
}
