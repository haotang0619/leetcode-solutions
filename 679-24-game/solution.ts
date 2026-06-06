function formatStr(nums: number[], op: string[], type: number) {
    const [a, b, c, d] = nums;
    const [x, y, z] = op;
    if(type === 0) return `${a}${x}${b}${y}${c}${z}${d}`;
    if(type === 1) return `(${a}${x}${b})${y}(${c}${z}${d})`;
    if(type === 2) return `((${a}${x}${b})${y}${c})${z}${d}`;
    if(type === 3) return `(${a}${x}(${b}${y}${c}))${z}${d}`;
    if(type === 4) return `${a}${x}((${b}${y}${c})${z}${d})`;
    return `${a}${x}(${b}${y}(${c}${z}${d}))`;
}

function findStr(cards: number[], now: number[], op: string[]) {
    if(now.length == 4) {
        for(let i = 0; i <= 5; i++) {
            const str = formatStr(now.map((i) => cards[i]), op, i);
            const num = eval(str);
            if(Math.abs(num - 24) <= 1e-5) return true;
        }
        return false;
    }
    for(let i = 0; i < 4; i++) {
        if(now.includes(i)) continue;
        now.push(i);
        for(let o of ['+', '-', '*', '/']) {
            op.push(o);
            let ans = findStr(cards, now, op);
            if(ans) return true;
            op.pop();
        }
        now.pop();
    }
    return false;
}

function judgePoint24(cards: number[]): boolean {
    return findStr(cards, [], []);
};
