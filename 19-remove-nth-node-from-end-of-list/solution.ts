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

class LinkListNode {
  val: number;
  next: LinkListNode | null;
  constructor(val?: number, next?: LinkListNode | null) {
    this.val = val === undefined ? 0 : val;
    this.next = next === undefined ? null : next;
  }
}

function removeNthFromEnd(
  head: LinkListNode | null,
  n: number,
): LinkListNode | null {
  let cnt = 1;
  let now = head;
  while (!!now?.next) {
    cnt++;
    now = now.next;
  }

  const target = cnt - n - 1;
  if (target < 0) return head?.next || null;

  cnt = 0;
  now = head;
  while (cnt++ !== target) now = now?.next || null;

  (now as LinkListNode).next = now?.next?.next || null;
  return head;
}
