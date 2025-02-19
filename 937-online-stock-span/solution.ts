class StockSpanner {
  private stack: [number, number][] = [];
  private idx = 0;

  next(price: number): number {
    while (price >= this.stack[this.stack.length - 1]?.[1]) this.stack.pop();
    const prev = this.stack[this.stack.length - 1]?.[0] ?? -1;
    this.stack.push([this.idx, price]);
    return this.idx++ - prev;
  }
}

/**
 * Your StockSpanner object will be instantiated and called as such:
 * var obj = new StockSpanner()
 * var param_1 = obj.next(price)
 */
