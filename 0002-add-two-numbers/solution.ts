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

class NumListNode {
  val: number;
  next: NumListNode | null;
  constructor(val?: number, next?: NumListNode | null) {
    this.val = val === undefined ? 0 : val;
    this.next = next === undefined ? null : next;
  }
}

function addTwoNumbers(
  l1: NumListNode | null,
  l2: NumListNode | null,
): NumListNode | null {
  const head = new NumListNode();
  let now = head;

  let pointer1 = l1;
  let pointer2 = l2;
  let carry = 0;

  while (!!now) {
    if (!!pointer1 && !!pointer2) {
      const sum = pointer1.val + pointer2.val + carry;
      now.val = sum % 10;
      carry = Math.floor(sum / 10);
      if (carry || pointer1.next || pointer2.next) {
        now.next = new NumListNode();
      }
      pointer1 = pointer1.next;
      pointer2 = pointer2.next;
    } else if (!!pointer1) {
      const sum = pointer1.val + carry;
      now.val = sum % 10;
      carry = Math.floor(sum / 10);
      if (carry || pointer1.next) {
        now.next = new NumListNode();
      }
      pointer1 = pointer1.next;
    } else if (!!pointer2) {
      const sum = pointer2.val + carry;
      now.val = sum % 10;
      carry = Math.floor(sum / 10);
      if (carry || pointer2.next) {
        now.next = new NumListNode();
      }
      pointer2 = pointer2.next;
    } else now.val = carry;
    now = now.next as NumListNode;
  }

  return head;
}
