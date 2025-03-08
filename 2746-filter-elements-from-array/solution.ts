type Fn = (n: number, i: number) => any

function filter(arr: number[], fn: Fn): number[] {
    const result = [];
    arr.forEach((a, i) => !!fn(a, i) && (result.push(a)));
    return result;
};
