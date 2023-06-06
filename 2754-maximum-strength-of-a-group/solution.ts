function maxStrength(nums: number[]): number {
    const pos = nums.filter((n) => n > 0).sort((a, b) => b - a);
    const neg = nums.filter((n) => n < 0).sort((a, b) => a - b);
    
    if(pos.length > 0) {
        let answer = pos.reduce((a, b) => a * b, 1);
        for(let i = 0; i + 2 <= neg.length; i += 2) {
            answer *= neg[i] * neg[i + 1];
        }
        return answer;
    }
    
    if(neg.length <= 1) {
        return nums.includes(0) ? 0 : neg[0];
    }
    
    let answer = 1;
    for(let i = 0; i + 2 <= neg.length; i += 2) {
        answer *= neg[i] * neg[i + 1];
    }
    return answer;
};
