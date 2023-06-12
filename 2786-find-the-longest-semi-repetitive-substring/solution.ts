function longestSemiRepetitiveSubstring(s: string): number {
    let answer = 0;
    let prev1 = -1;
    let prev2 = -1
    for(let i = 0; i < s.length - 1; i++) {
        if(s[i] === s[i + 1]) {
            if(prev2 >= 0) {
                const len = i - prev1;
                answer = answer > len ? answer : len;
                prev1 = prev2;
            }
            prev2 = i;
        }
    }
    const final = s.length - 1 - prev1;
    answer = answer > final ? answer : final;
    return answer;
};
