type Ranges = [number, number];

class MaxDistanceHeap {
  private heap: Ranges[];
  private n: number;

  constructor(n) {
    this.heap = [];
    this.n = n;
  }

  private comp(node1: Ranges, node2: Ranges) {
    if (!node1) return -1;
    if (!node2) return 1;
    const dis1 = Math.floor((node1[1] - node1[0]) / 2);
    const dis2 = Math.floor((node2[1] - node2[0]) / 2);
    if (dis1 !== dis2) return dis1 - dis2;
    return node2[0] - node1[0];
  }

  private swap(idx1: number, idx2: number) {
    [this.heap[idx1], this.heap[idx2]] = [this.heap[idx2], this.heap[idx1]];
  }

  private heapify(idx: number) {
    let [largest, left, right] = [idx, idx * 2 + 1, idx * 2 + 2];
    if (this.comp(this.heap[largest], this.heap[left]) < 0) largest = left;
    if (this.comp(this.heap[largest], this.heap[right]) < 0) largest = right;

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

  insert(range: Ranges) {
    this.heap.push(range);
    this.heapifyAll();
    // console.log(this.heap)
  }

  delete(idx = 0) {
    const last = this.heap.length - 1;
    if (idx <= last) {
      this.swap(idx, last);
      const deleted = this.heap.pop() as Ranges;
      this.heapifyAll();
      return deleted;
    } else return null;
  }

  deleteByNum(num: number) {
    const numAsLeft = this.heap.findIndex(([a, b]) => a === num);
    const range1 = JSON.parse(JSON.stringify(this.heap[numAsLeft] || ''));
    if (!!range1) this.delete(numAsLeft);

    const numAsRight = this.heap.findIndex(([a, b]) => b === num);
    const range2 = JSON.parse(JSON.stringify(this.heap[numAsRight] || ''));
    if (!!range2) this.delete(numAsRight);

    let newRange: Ranges;
    if (!range1 || range1[1] >= this.n)
      newRange = [range2[0], range2[0] + (this.n - 1 - range2[0]) * 2];
    else if (!range2 || range2[0] < 0) newRange = [-range1[1], range1[1]];
    else newRange = [range2[0], range1[1]];

    if (newRange[0] >= 0 || newRange[1] < this.n) this.insert(newRange);
  }
}

class ExamRoom {
  private heap: MaxDistanceHeap;
  private n: number;

  constructor(n: number) {
    this.heap = new MaxDistanceHeap(n);
    this.n = n;
  }

  seat(): number {
    const range = this.heap.delete();
    if (!range) {
      this.heap.insert([0, 2 * this.n - 1]);
      return 0;
    }

    const newSeat = Math.floor((range[0] + range[1]) / 2);
    if (range[0] >= 0) this.heap.insert([range[0], newSeat]);
    if (range[1] < this.n) this.heap.insert([newSeat, range[1]]);
    return newSeat;
  }

  leave(p: number): void {
    this.heap.deleteByNum(p);
  }
}

/**
 * Your ExamRoom object will be instantiated and called as such:
 * var obj = new ExamRoom(n)
 * var param_1 = obj.seat()
 * obj.leave(p)
 */
