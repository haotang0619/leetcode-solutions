function longestAlternatingSubarray(nums: number[], threshold: number): number {
    let ans = 0;
    let start = -1;
    let flag = -1;
    for(let i = 0; i < nums.length; i++) {
        if(flag === -1) {
            if(nums[i] % 2 === 0 && nums[i] <= threshold) {
                ans = Math.max(ans, 1);
                start = i;
                flag = 1;
            }
        } else if (flag === 1){
            if(nums[i] % 2 === 1 && nums[i] <= threshold) {
                ans = Math.max(ans, i - start + 1);
                flag = 0;
            } else {
                 flag = -1;
                 i--;   
            }
        } else {
            if(nums[i] % 2 === 0 && nums[i] <= threshold) {
                ans = Math.max(ans, i - start + 1);
                flag = 1;
            } else {
                flag = -1;
                i--;
            }
        }
    }
    return ans;
};
