function rowAndMaximumOnes(mat: number[][]): number[] {
    let idx = -1;
    let maxCnt = -1;
    
    for(let i = 0; i < mat.length; i++) {
        const cnt = mat[i].filter((j) => j === 1).length;
        if(cnt > maxCnt) {
            idx = i;
            maxCnt = cnt;
        }
    }
    
    return [idx, maxCnt]
};
