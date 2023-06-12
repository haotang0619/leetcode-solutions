function partitionString(s: string): number {
    const seen = new Set();
    let answer = 1;
    for(let i = 0; i < s.length; i++) {
        if(seen.has(s[i])) {
            answer++;
            seen.clear();
        }
        seen.add(s[i])
    }
    return answer;
};
