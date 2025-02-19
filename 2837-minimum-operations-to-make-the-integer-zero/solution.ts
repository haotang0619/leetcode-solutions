function makeTheIntegerZero(num1: number, num2: number): number {
    for(let i = 1; i <= 61; i++) {
        num1 -= num2;
        if(num1 <= 0) return -1;
        const cnt = num1.toString(2).match(/[1]/g)?.length || 0;
        if(cnt <= i && num1 >= i) return i;
    }
    return -1;
};
