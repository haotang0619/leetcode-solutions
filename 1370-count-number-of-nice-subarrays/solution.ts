function numberOfSubarrays(nums: number[], k: number): number {
  let ans = 0;
  let p1 = 0;
  let p2 = 0;
  let p3 = 0;
  let count = 0;
  while (p3 <= nums.length) {
    if (p3 === nums.length || nums[p3] % 2) ++count;
    if (count > k) {
      let cnt = 1;
      while (nums[p1] % 2 !== 1) ++p1, ++cnt;
      ans += cnt * (p3 - p2);
      ++p1;
      --count;
    }
    if (nums[p3] % 2) p2 = p3;
    ++p3;
  }
  return ans;
}
