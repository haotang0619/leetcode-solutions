
type HeapElement = { val: number; pos: number };

// O(NlogN) => too slow
class MaxHeap {
  private heap: HeapElement[] = [];

  constructor(...elements: HeapElement[]) {
    elements.forEach((element) => this.insert(element));
  }

  private swap(idx1: number, idx2: number) {
    [this.heap[idx1], this.heap[idx2]] = [this.heap[idx2], this.heap[idx1]];
  }

  private heapify(idx: number) {
    let [largest, left, right] = [idx, idx * 2 + 1, idx * 2 + 2];
    if (this.heap[left]?.val > this.heap[largest].val) largest = left;
    if (this.heap[right]?.val > this.heap[largest].val) largest = right;

    if (largest !== idx) {
      this.swap(largest, idx);
      this.heapify(largest);
    }
  }

  private heapifyAll() {
    const len = this.heap.length;
    for (let i = Math.floor(len / 2) - 1; i >= 0; i--) {
      this.heapify(i);
    }
  }

  insert(element: HeapElement) {
    this.heap.push(element);
    this.heapifyAll();
  }

  delete(idx = 0) {
    const last = this.heap.length - 1;
    if (idx <= last) {
      this.swap(idx, last);

      const deleted = this.heap.pop() as HeapElement;
      this.heapifyAll();

      return deleted.val;
    } else return null;
  }

  peek() {
    return this.heap[0];
  }

  print() {
    console.log(this.heap);
  }
}

// https://leetcode.com/problems/sliding-window-maximum/solutions/3557731/4-sliding-window-maximum:
function maxSlidingWindow(nums: number[], k: number): number[] {
  const deque: { val: number; pos: number }[] = [];
  const answer: number[] = [];

  for (let i = 0; i < nums.length; i++) {
    while (deque[0]?.pos <= i - k) deque.shift();
    while (deque.slice(-1)[0]?.val <= nums[i]) deque.pop();
    deque.push({ val: nums[i], pos: i });
    if (i >= k - 1) answer.push(deque[0]?.val);
  }
  return answer;
}
