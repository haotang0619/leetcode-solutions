function removeDigit(number: string, digit: string): string {
    const result: string[] = [];
    for(let i = 0; i < number.length; i++) {
        if(number[i] === digit) result.push(`${number.slice(0, i)}${number.slice(i + 1)}`)
    }
    return result.sort((a, b) => (b.length - a.length) || b > a ? 1 : -1)[0]
};
