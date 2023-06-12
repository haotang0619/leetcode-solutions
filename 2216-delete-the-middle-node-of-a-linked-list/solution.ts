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

function deleteMiddle(head: ListNode | null): ListNode | null {
  let n = 0;
  let now = head;
  while (now) (now = now.next), n++;
  let pos = Math.floor(n / 2);
  if (pos === 0) return null;

  n = 0;
  now = head;
  while (n < pos - 1) (now = (now as ListNode).next), n++;
  (now as ListNode).next = now?.next?.next ?? null;
  return head;
}
