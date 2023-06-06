function differenceOfDistinctValues(grid: number[][]): number[][] {
    const m = grid.length;
    const n = grid[0].length;
    const answer = Array.from({ length: m }).map(() => []);
    
    for(let i = 0; i < m; i++) {
        for(let j = 0; j < n; j++) {
            const set1 = new Set();
            for(let x = 0; x < i; x++) {
                const y = j - (i - x);
                if(y >= 0) set1.add(grid[x][y])
            }
            
            const set2 = new Set();
            for(let x = i + 1; x < m; x++) {
                const y = j + (x - i);
                if(y < n) set2.add(grid[x][y])
            }
            
            answer[i][j] = Math.abs(set1.size - set2.size);
        }
    }
    return answer;
};
