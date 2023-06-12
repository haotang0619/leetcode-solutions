function countNegatives(grid: number[][]): number {
    const m = grid.length;
    const n = grid[0].length
    let until = n;
    let answer = 0;
    for(let i = 0; i < m; i++){
        answer += n - until;
        for(let j = 0; j < until; j++){
            if(grid[i][j] < 0) {
                answer += until - j;
                until = j;
                break;
            }
        }
    }
    return answer;
};
