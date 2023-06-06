function semiOrderedPermutation(nums: number[]): number {
    const len = nums.length;
    const idx1 = nums.findIndex((n) => n === 1);
    const idx2 = nums.findIndex((n) => n === len);
    return idx1 + (len - idx2 - 1) + (idx1 > idx2 ? -1 : 0)
};
