function findDifference(nums1: number[], nums2: number[]): number[][] {
  const records1: Record<number, number> = {};
  const records2: Record<number, number> = {};
  nums1.forEach((num) => (records1[num] = 1));
  nums2.forEach((num) => (records2[num] = 1));
  const answer: number[][] = [[], []];
  nums1.forEach((num) => {
    if (records1[num] === 1 && !records2[num]) {
      answer[0].push(num);
      records1[num] = 2;
    }
  });
  nums2.forEach((num) => {
    if (records2[num] === 1 && !records1[num]) {
      answer[1].push(num);
      records2[num] = 2;
    }
  });
  return answer;
}
