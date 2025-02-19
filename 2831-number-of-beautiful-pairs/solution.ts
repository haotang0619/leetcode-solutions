const gcd = (a, b) => !b ? a : gcd(b, a % b);
function countBeautifulPairs(nums: number[]): number {
    let ans = 0;
    for(let i = 0; i < nums.length - 1; i++){
        for(let j = i + 1; j < nums.length; j++){
            const a = Number(String(nums[i])[0]), b = nums[j] % 10;
            if(gcd(a, b) === 1) ans++;
        }
    }
    return ans;
};
