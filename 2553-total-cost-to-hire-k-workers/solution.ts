type HeapElement = [number, number];
class MinHeap {
  private heap: HeapElement[] = [];

  constructor(...elements: HeapElement[]) {
    elements.forEach((element) => this.insert(element));
  }

  get size() {
    return this.heap.length;
  }

  private comp(element1: HeapElement, element2: HeapElement): number {
    if (!element1 || !element2) return NaN;
    if (element1[0] === element2[0]) return element1[1] - element2[1];
    return element1[0] - element2[0];
  }

  private swap(idx1: number, idx2: number) {
    [this.heap[idx1], this.heap[idx2]] = [this.heap[idx2], this.heap[idx1]];
  }

  private heapifyUp(idx: number) {
    let parent = Math.floor((idx - 1) / 2);

    if (this.comp(this.heap[idx], this.heap[parent]) < 0) {
      this.swap(idx, parent);
      this.heapifyUp(parent);
    }
  }

  private heapifyDown(idx: number) {
    let [smallest, left, right] = [idx, idx * 2 + 1, idx * 2 + 2];
    if (this.comp(this.heap[left], this.heap[smallest]) < 0) smallest = left;
    if (this.comp(this.heap[right], this.heap[smallest]) < 0) smallest = right;

    if (smallest !== idx) {
      this.swap(smallest, idx);
      this.heapifyDown(smallest);
    }
  }

  insert(element: HeapElement) {
    this.heap.push(element);
    this.heapifyUp(this.heap.length - 1);
  }

  delete() {
    const last = this.heap.length - 1;
    if (last >= 0) {
      this.swap(0, last);

      const deleted = this.heap.pop() as HeapElement;
      this.heapifyDown(0);

      return deleted;
    } else return null;
  }
}

function totalCost(costs: number[], k: number, candidates: number): number {
  let p1 = 0;
  let p2 = costs.length - 1;
  let answer = 0;
  let from = 0;
  const heap = new MinHeap();

  while (k--) {
    while (p1 <= p2 && heap.size < candidates * 2) {
      if (from === 0) heap.insert([costs[p1], p1]), p1++;
      else heap.insert([costs[p2], p2]), p2--;
      from = 1 - from;
    }
    const result = heap.delete() as HeapElement;
    answer += result[0];
    if (result[1] < p1) from = 0;
    else from = 1;
  }
  return answer;
}
