function countServers(n: number, logs: number[][], x: number, queries: number[]): number[] {
    logs.sort((a, b) => a[1] - b[1]);
    const indexes = [...Array(queries.length).keys()].sort((a, b) => queries[a] - queries[b]);
    queries.sort((a, b) => a - b);
    const answer = [];
    const deque = [];
    const records = {};
    let cnt = 0;
    let idx = 0;
    
    queries.forEach((q, i) => {
        while(logs[idx]?.[1] <= q) {
            if(logs[idx][1] >= q - x) {
                deque.push(logs[idx]);
                const [server] = logs[idx];
                if(!records[server]) cnt++;
                records[server] = (records[server] ?? 0) + 1;
            }
            idx++;
        }
        while(deque[0]?.[1] < q - x) {
            const [server] = deque.shift();
            if (records[server] === 1) {
                delete records[server]; cnt--;
            } else records[server]--;
        }
        answer[indexes[i]] = n - cnt;
    });
    return answer;
};
