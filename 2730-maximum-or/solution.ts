function maximumOr(nums: number[], k: number): number {
  const records: number[] = [];

  const n = nums.length;
  for (let i = 0; i < n; i++) {
    const str = nums[i].toString(2);
    const len = str.length;
    for (let j = 0; j < len; j++) {
      records[j] = records[j] ?? 0;
      if (str[len - j - 1] === '1') records[j]++;
    }
  }

  let max = -1;
  for (let i = 0; i < n; i++) {
    let now = nums[i];
    const temp: number[] = JSON.parse(JSON.stringify(records));
    for (let j = 0; j < k; j++) now *= 2;

    const str1 = nums[i].toString(2);
    const str2 = now.toString(2);
    const len1 = str1.length;
    const len2 = str2.length;

    for (let x = 0; x < len1; x++) {
      if (str1[len1 - x - 1] === '1') temp[x]--;
    }
    for (let x = 0; x < len2; x++) {
      temp[x] = temp[x] ?? 0;
      if (str2[len2 - x - 1] === '1') temp[x]++;
    }
    max = Math.max(
      max,
      parseInt(
        temp
          .map((t) => (t > 0 ? 1 : 0))
          .reverse()
          .join(''),
        2,
      ),
    );
  }

  return max;
}
