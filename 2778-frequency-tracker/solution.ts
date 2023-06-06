class FrequencyTracker {
  private numToFreq: Record<number, number> = {};
  private freqToNum: Record<number, Set<Number>> = {};

  add(number: number): void {
    const freq = this.numToFreq[number] ?? 0;
    if (freq > 0) this.freqToNum[freq].delete(number);

    if (!this.freqToNum[freq + 1]) this.freqToNum[freq + 1] = new Set();
    this.freqToNum[freq + 1].add(number);
    this.numToFreq[number] = freq + 1;
  }

  deleteOne(number: number): void {
    const freq = this.numToFreq[number] ?? 0;
    if (freq === 0) return;
    this.freqToNum[freq].delete(number);

    if (freq - 1 > 0) this.freqToNum[freq - 1].add(number);
    this.numToFreq[number] = freq - 1;
  }

  hasFrequency(frequency: number): boolean {
    return this.freqToNum[frequency]?.size > 0;
  }
}

/**
 * Your FrequencyTracker object will be instantiated and called as such:
 * var obj = new FrequencyTracker()
 * obj.add(number)
 * obj.deleteOne(number)
 * var param_3 = obj.hasFrequency(frequency)
 */
