const nextCurr = (current: string) => {
    if(current === 'a') return 'b'
    return current === 'b' ? 'c' : 'a';
}

function addMinimum(word: string): number {
    let current = 'a';
    let ans = 0;
    
    for(let i = 0; i < word.length; i++){
        while(word[i] !== current) {
            ans++; current = nextCurr(current);
        }
        current = nextCurr(current);
    }
    if(word.slice(-1)[0] === 'a') ans += 2;
    if(word.slice(-1)[0] === 'b') ans += 1;
    
    return ans;
};
