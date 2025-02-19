function maximumNumberOfStringPairs(words: string[]): number {
    let ans = 0;
    let seen = new Set();
    for(let w of words) {
        const wRev = w.split('').reverse().join('');
        if(seen.has(wRev)){
            ans++; seen.delete(wRev);
        }else seen.add(w);
    }
    return ans;
};
