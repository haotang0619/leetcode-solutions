function matrixSumQueries(n: number, queries: number[][]): number {
    const len = queries.length;
    const colSet = new Set();
    const rowSet = new Set();
    let answer = 0;
    
    for(let i = len - 1; i >= 0; i--){
        const [type, idx, val] = queries[i];
        if (type === 0 && !rowSet.has(idx)) {
            rowSet.add(idx);
            answer += val * (n - colSet.size);
        } else if (type === 1 && !colSet.has(idx)) {
            colSet.add(idx);
            answer += val * (n - rowSet.size);
        }
    }
    return answer;
};
