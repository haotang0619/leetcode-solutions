const INF = 1e9 + 7;

function minimizeConcatenatedLength(words: string[]): number {
    const dp: Record<string, number>[] = [{}];
    dp[0][`${words[0][0]}${words[0][words[0].length - 1]}`] = words[0].length;
    
    for(let i = 1; i < words.length; i++) {
        dp[i] = {};
        for(const now of Object.keys(dp[i - 1])){
            if(typeof dp[i - 1][now] === 'number'){
                const head = words[i][0], end = words[i][words[i].length - 1];
                const headNow = `${head}${now[1]}`;
                const endNow = `${now[0]}${end}`;
                const headLen = words[i].length - (end === now[0] ? 1 : 0);
                const endLen = words[i].length - (head === now[1] ? 1 : 0);

                dp[i][headNow] = Math.min(dp[i][headNow] || INF, dp[i - 1][now] + headLen);
                dp[i][endNow] = Math.min(dp[i][endNow] || INF, dp[i - 1][now] + endLen);
            }
        }
    }
    return Math.min(...Object.values(dp[words.length - 1]));
};
