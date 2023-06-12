function isFascinating(n: number): boolean {
    const str = `${n}${n * 2}${n * 3}`;
    const records = {};
    for(const s of str) records[s] = (records[s] ?? 0) + 1;
    return Object.keys(records).length === 9 && !records[0] && str.length === 9;
};
