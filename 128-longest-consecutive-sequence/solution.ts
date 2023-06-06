function longestConsecutive(nums: number[]): number {
  const record: Record<number, boolean> = {};
  nums.forEach((num) => (record[num] = true));

  return nums.reduce((ans, num) => {
    let now = 1;
    if (record[num]) {
      delete record[num];
      let prev = num - 1;
      while (record[prev]) {
        delete record[prev];
        prev--;
        now += 1;
      }
      let next = num + 1;
      while (record[next]) {
        delete record[next];
        next++;
        now += 1;
      }
    }
    return Math.max(ans, now);
  }, 0);
}
