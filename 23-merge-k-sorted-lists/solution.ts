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

const MIN = 10001;

function mergeKLists(lists: Array<ListNode | null>): ListNode | null {
  const length = lists.length;
  let head: ListNode | null = null;
  let prev: ListNode | null = null;

  while (true) {
    let pos = -1;
    let val = MIN;
    for (let i = 0; i < length; i++) {
      if ((lists[i]?.val ?? MIN + 1) < val) {
        pos = i;
        val = lists[i]?.val as number;
      }
    }

    if (pos === -1) break;

    const now = new ListNode(val, null);
    if (!!prev) prev.next = now;
    else head = now;
    prev = now;

    lists[pos] = lists[pos].next;
  }

  return head;
}
