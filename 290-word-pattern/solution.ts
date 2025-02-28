function wordPattern(pattern: string, s: string): boolean {
    const n = pattern.length;
    const arr = s.split(" ");
    if(arr.length != n) return false;
    const mp1 = {}, mp2 = {};
    for(let i = 0; i < n; i++) {
        if(!mp1[pattern[i]]) {
            mp1[pattern[i]] = arr[i];
            if(typeof mp2[arr[i]] !== 'string') mp2[arr[i]] = pattern[i];
            else if(mp2[arr[i]] !== pattern[i]) return false;
        } else if(mp1[pattern[i]] !== arr[i]) return false;
    }
    return true;
};
