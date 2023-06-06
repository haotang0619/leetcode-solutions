function minimizedStringLength(s: string): number {
    const records = {};
    for(let i = 0; i < s.length; i++) records[s[i]] = true;
    return Object.keys(records).length;
};
