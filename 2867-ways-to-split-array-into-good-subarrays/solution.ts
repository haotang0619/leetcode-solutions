const MOD = 1e9 + 7;
function numberOfGoodSubarraySplits(nums: number[]): number {
    const sum = nums.reduce((a, b) => a + b);
    if(sum <= 1) return sum;
    
    let ans = 1;
    let prev = -1;
    for(let i = 0; i < nums.length; i++) {
        if(nums[i] === 1){
            if(prev === -1) prev = i;
            else {
                ans = (ans * (i - prev)) % MOD;
                prev = i;
            };
        }
    }
    
    return ans;
};
