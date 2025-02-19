function findValueOfPartition(nums: number[]): number {
    const n = nums.length;
    nums.sort((a, b) => a - b);
    let mini = 1e9 + 7;
    for(let i = 0; i < n - 1; i++) {
        const gap = nums[i + 1] - nums[i];
        mini = mini < gap ? mini : gap;
    }
    return mini;
};
