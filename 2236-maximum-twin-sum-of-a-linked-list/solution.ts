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

function pairSum(head: ListNode | null): number {
  let n = 0;
  let now = head;
  while (now) n++, (now = now.next);
  const records: number[] = [];
  let answer = -1;

  let i = 0;
  now = head;
  while (now) {
    if (i < Math.floor(n / 2)) records[i] = now.val;
    else {
      const sum = records[n - 1 - i] + now.val;
      answer = answer > sum ? answer : sum;
    }
    now = now.next;
    i++;
  }
  return answer;
}
