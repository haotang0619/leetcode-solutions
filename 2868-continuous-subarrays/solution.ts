type Segment = { start: number; end: number; max: number; min: number };

const build = (
  tree: Segment[],
  nums: number[],
  start: number,
  end: number,
  idx: number,
): void => {
  if (start === end) {
    const value = nums[start];
    tree[idx] = { start, end, max: value, min: value };
    return;
  }

  const mid = Math.floor((start + end) / 2);
  const left = idx * 2 + 1;
  const right = idx * 2 + 2;
  build(tree, nums, start, mid, left);
  build(tree, nums, mid + 1, end, right);
  const max = Math.max(tree[left].max, tree[right].max);
  const min = Math.min(tree[left].min, tree[right].min);

  tree[idx] = { start, end, max, min };
};

const query = (
  tree: Segment[],
  start: number,
  end: number,
  idx: number,
): {max: number, min: number} => {
    const {start:s, end: e, max, min} = tree[idx];
    if(s >= start && e <= end) return { max, min };
    if(s > end || e < start) return { max: -1, min: 1e9 + 7 };
    
    const mid = Math.floor((s + e) / 2);
    const left = query(tree, start, end, idx * 2 + 1);
    const right = query(tree, start, end, idx * 2 + 2);
    return { max: Math.max(left.max, right.max), min: Math.min(left.min, right.min) };
}

function continuousSubarrays(nums: number[]): number {
    let p1 = 0;
    let ans = 0;
    const tree = [];
    build(tree, nums, 0, nums.length - 1, 0);
    
    for(let p2 = 1; p2 < nums.length; p2++) {
        while(p1 < p2) {
            const {max, min} = query(tree, p1, p2 - 1, 0);
            if(Math.abs(nums[p2] - min) <= 2 && Math.abs(nums[p2] - max) <= 2) break;
            ans += p2 - p1;
            p1++;
        }
    }
    let left = nums.length - p1;
    return ans + ((1 + left) * left / 2);
};
