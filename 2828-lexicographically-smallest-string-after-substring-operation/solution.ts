function prevChar(c) {
    const c1 = String.fromCharCode(c.charCodeAt(0) - 1);
    return c1 === '`' ? 'z' : c1;
}

function smallestString(s: string): string {
    let p1 = -1; let p2 = -1;
    for(let i = 0; i < s.length; i++) {
        if(p1 === -1 && s[i] !== 'a') p1 = i;
        else if(p1 !== -1 && s[i] === 'a') p2 = i;
        if(p1 >= 0 && p2 >= 0) break;
    }
    p1 = p1 === -1 ? s.length - 1 : p1;
    p2 = p2 === -1 ? s.length : p2;
    let ans = '';
    for(let i = 0; i < s.length; i++) {
        if(i >= p1 && i < p2) ans += prevChar(s[i])
        else ans += s[i];
    }
    return ans
};
