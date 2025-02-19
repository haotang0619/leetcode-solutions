const MOD = 1e9 + 7;
const pascalTriangle: number[][] = [[], [1, 1]];
for (let i = 2; i <= 1000; i++) {
  pascalTriangle[i] = [];
  for (let j = 0; j <= Math.floor(i / 2); j++) {
    if (j === 0) pascalTriangle[i][j] = pascalTriangle[i][i] = 1;
    else {
      pascalTriangle[i][j] = pascalTriangle[i][i - j] =
        (pascalTriangle[i - 1][j - 1] + pascalTriangle[i - 1][j]) % MOD;
    }
  }
}

function numOfWays(nums: number[], depth = 0): number {
  if (nums.length <= 2) return depth === 0 ? 0 : 1;
  const root = nums[0];
  const leftTree = nums.filter((n) => n < root);
  const rightTree = nums.filter((n) => n > root);

  const leftWays = numOfWays(leftTree, depth + 1);
  const rightWays = numOfWays(rightTree, depth + 1);
  const answer =
    (((BigInt(leftWays) * BigInt(rightWays)) % BigInt(MOD)) *
      BigInt(pascalTriangle[nums.length - 1][leftTree.length])) %
    BigInt(MOD);
  return depth === 0 ? Number(answer) - 1 : Number(answer);
}
