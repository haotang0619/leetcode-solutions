const INF = 2 ** 31 + 1;
function findPeakElement(nums: number[]): number {
  let start = 0;
  let end = nums.length - 1;
  while (start <= end) {
    const mid = Math.floor((start + end) / 2);
    if (
      nums[mid] > (nums[mid + 1] ?? -INF) &&
      nums[mid] > (nums[mid - 1] ?? -INF)
    ) {
      return mid;
    }
    if (nums[mid] > nums[mid + 1]) end = mid;
    else start = mid + 1;
  }
  return 0;
}
