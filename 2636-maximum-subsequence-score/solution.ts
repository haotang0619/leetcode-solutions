class MinHeap {
  private heap: number[] = [];
  sum: number = 0;

  constructor(...elements: number[]) {
    elements.forEach((element) => this.insert(element));
  }

  private swap(idx1: number, idx2: number) {
    [this.heap[idx1], this.heap[idx2]] = [this.heap[idx2], this.heap[idx1]];
  }

  private heapifyUp(idx: number) {
    let parent = Math.floor((idx - 1) / 2);

    if (this.heap[idx] < this.heap[parent]) {
      this.swap(idx, parent);
      this.heapifyUp(parent);
    }
  }

  private heapifyDown(idx: number) {
    let [smallest, left, right] = [idx, idx * 2 + 1, idx * 2 + 2];
    if (this.heap[left] < this.heap[smallest]) smallest = left;
    if (this.heap[right] < this.heap[smallest]) smallest = right;

    if (smallest !== idx) {
      this.swap(smallest, idx);
      this.heapifyDown(smallest);
    }
  }

  insert(element: number) {
    this.heap.push(element);
    this.sum += element;
    this.heapifyUp(this.heap.length - 1);
  }

  delete() {
    const last = this.heap.length - 1;
    if (last >= 0) {
      this.swap(0, last);

      const deleted = this.heap.pop() as number;
      this.sum -= deleted;
      this.heapifyDown(0);

      return deleted;
    } else return null;
  }
}

function maxScore(nums1: number[], nums2: number[], k: number): number {
  const indexes = [...nums2.keys()].sort((a, b) => nums2[b] - nums2[a]);
  const heap = new MinHeap();
  let answer = 0;
  for (let i = 0; i < indexes.length; i++) {
    const idx = indexes[i];
    heap.insert(nums1[idx]);
    if (i >= k) heap.delete();
    if (i >= k - 1) {
      const score = heap.sum * nums2[idx];
      answer = answer > score ? answer : score;
    }
  }
  return answer;
}
