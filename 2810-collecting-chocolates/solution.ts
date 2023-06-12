function minCost(nums: number[], x: number): number {
    const n = nums.length;
    const minCosts = [...nums];
    const totalCosts = [];
    
    let maxOp = 0;
    for(let i = 0; i < n; i++){
        let minus = 0;
        const toUpdate = []
        for(let j = 0; j < n; j++) {
            const idx = j + i < n ? j + i : j - n + i;
            const price = nums[idx];
            if(price < minCosts[j]) { 
                minus += minCosts[j] - price;
                toUpdate.push([j, price]);
            }
        }
        if(minus > x * (i - maxOp)) {
            maxOp = i;
            toUpdate.forEach(([j, price]) => minCosts[j] = price)
        }
    }
    return minCosts.reduce((a, b) => a + b) + x * maxOp;
};
