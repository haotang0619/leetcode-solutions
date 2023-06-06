function maxDivScore(nums: number[], divisors: number[]): number {
    let ans = 1e9 + 7;
    let maxScore = -1;
    
    divisors.forEach((div) => {
        const score = nums.filter((n) => n % div === 0).length;
        if(score > maxScore || (score === maxScore && div <= ans)) {
            ans = div;
            maxScore = score;
        }
    });
    
    return ans;
};
