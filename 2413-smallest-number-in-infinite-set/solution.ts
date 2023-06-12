class SmallestInfiniteSet {
  private set = Array.from({ length: 1000 }).map(() => true);
  popSmallest(): number {
    const smallest = this.set.findIndex((b) => b);
    this.set[smallest] = false;
    return smallest + 1;
  }

  addBack(num: number): void {
    this.set[num - 1] = true;
  }
}

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * var obj = new SmallestInfiniteSet()
 * var param_1 = obj.popSmallest()
 * obj.addBack(num)
 */
