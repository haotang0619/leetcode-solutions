type Segment = { start: number; end: number; value: number; lazy: number };

const buildSegmentTree = (
  segmentTree: Segment[],
  nums: number[],
  start: number,
  end: number,
  idx: number,
): void => {
  if (start === end) {
    const value = nums[start];
    segmentTree[idx] = { start, end, value, lazy: 0 };
    return;
  }

  const mid = Math.floor((start + end) / 2);
  const left = idx * 2 + 1;
  const right = idx * 2 + 2;
  buildSegmentTree(segmentTree, nums, start, mid, left);
  buildSegmentTree(segmentTree, nums, mid + 1, end, right);
  const value = segmentTree[left].value + segmentTree[right].value;

  segmentTree[idx] = { start, end, value, lazy: 0 };
};

const updateSegment = (segmentTree: Segment[], idx: number) => {
  const { start, end, value, lazy } = segmentTree[idx];
  const len = end - start + 1;
  segmentTree[idx].value = len - value;
  segmentTree[idx].lazy = lazy === 1 ? 0 : 1;
  return;
};

const updateSegmentTree = (
  segmentTree: Segment[],
  left: number,
  right: number,
  idx: number,
): void => {
  if (left > right) return;
  const { start, end, lazy } = segmentTree[idx];
  if (start === left && end === right) {
    updateSegment(segmentTree, idx);
    return;
  }
  if (lazy === 1) {
    segmentTree[idx].lazy = 0;
    updateSegment(segmentTree, idx * 2 + 1);
    updateSegment(segmentTree, idx * 2 + 2);
  }

  const mid = Math.floor((start + end) / 2);
  updateSegmentTree(segmentTree, left, Math.min(right, mid), idx * 2 + 1);
  updateSegmentTree(segmentTree, Math.max(left, mid + 1), right, idx * 2 + 2);

  segmentTree[idx].value =
    segmentTree[idx * 2 + 1].value + segmentTree[idx * 2 + 2].value;
};

function handleQuery(
  nums1: number[],
  nums2: number[],
  queries: number[][],
): number[] {
  const segmentTree: Segment[] = [];
  buildSegmentTree(segmentTree, nums1, 0, nums1.length - 1, 0);
  let sum: number = nums2.reduce((a, b) => a + b);

  return queries.reduce((answer, [q1, q2, q3]) => {
    if (q1 === 1) updateSegmentTree(segmentTree, q2, q3, 0);
    if (q1 === 2) sum += segmentTree[0].value * q2;
    if (q1 === 3) answer.push(sum);
    return answer;
  }, []);
}
