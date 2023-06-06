function buyChoco(prices: number[], money: number): number {
    prices.sort((a, b) => a - b);
    const mon = money - prices[0] - prices[1]
    return mon >= 0 ? mon : money;
};
