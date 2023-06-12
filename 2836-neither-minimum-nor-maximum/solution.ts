function findNonMinOrMax(nums: number[]): number {
    const min = Math.min(...nums);
    const max = Math.max(...nums);
    for(let i of nums){
        if(i !== min && i !== max) return i;
    }
    return -1;
};
