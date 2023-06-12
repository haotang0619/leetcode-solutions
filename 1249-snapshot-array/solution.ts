class SnapshotArray {
  private records: Record<number, Record<number, number>> = {};
  private snapId = 0;
  constructor(length: number) {}

  set(index: number, val: number): void {
    if (!this.records[index]) this.records[index] = {};
    this.records[index][this.snapId] = val;
  }

  snap(): number {
    this.snapId++;
    return this.snapId - 1;
  }

  get(index: number, snap_id: number): number {
    if (!this.records[index]) return 0;
    let val = 0;
    for (const i of Object.keys(this.records[index])) {
      if (parseInt(i) > snap_id) break;
      else val = this.records[index][i];
    }
    return val;
  }
}

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * var obj = new SnapshotArray(length)
 * obj.set(index,val)
 * var param_2 = obj.snap()
 * var param_3 = obj.get(index,snap_id)
 */
