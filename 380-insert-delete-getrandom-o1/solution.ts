class RandomizedSet {
  private map = new Map<number, number>();
  private arr: number[] = [];
  private del: number = 0;

  insert(val: number): boolean {
    if (!this.map.has(val)) {
      this.map.set(val, this.arr.length);
      this.arr.push(val);
      return true;
    }
    return false;
  }

  remove(val: number): boolean {
    const idx = this.map.get(val);
    if (idx !== undefined) {
      this.map.set(this.arr[this.del], idx);
      [this.arr[idx], this.arr[this.del]] = [this.arr[this.del], this.arr[idx]];
      this.del++;
      this.map.delete(val);
      return true;
    }
    return false;
  }

  getRandom(): number {
    const rand =
      this.del + Math.floor(Math.random() * (this.arr.length - this.del));
    return this.arr[rand];
  }
}
