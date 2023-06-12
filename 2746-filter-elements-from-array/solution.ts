function filter(arr: number[], fn: (n: number, i: number) => any): number[] {
    const ans = [];
    for(let i = 0; i < arr.length; i++) fn(arr[i], i) ? ans.push(arr[i]) : null
    return ans;
 };
