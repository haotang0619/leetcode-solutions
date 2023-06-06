const MAX = 1000001;
const MIN = -MAX;

function findMedianSortedArrays(nums1: number[], nums2: number[]): number {
  const len1 = nums1.length;
  const len2 = nums2.length;
  if (len1 > len2) {
    return findMedianSortedArrays(nums2, nums1);
  }

  let start = 0;
  let end = len1;
  const size = len1 + len2;
  const halfSize = Math.ceil(size / 2);

  while (start <= end) {
    const mid1 = Math.floor((start + end) / 2);
    const left1 = nums1[mid1 - 1] ?? MIN;
    const right1 = nums1[mid1] ?? MAX;

    const mid2 = halfSize - mid1;
    const left2 = nums2[mid2 - 1] ?? MIN;
    const right2 = nums2[mid2] ?? MAX;

    if (left1 <= right2 && left2 <= right1) {
      if (size % 2 === 0) {
        const sorted = [left1, right1, left2, right2].sort((a, b) => a - b);
        return (sorted[1] + sorted[2]) / 2;
      }
      return Math.max(left1, left2);
    }

    if (left1 > right2) end = mid1;
    else start = mid1 + 1;
  }

  return 0;
}
