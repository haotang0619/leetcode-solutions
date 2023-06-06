class TimeLimitedCache {
    private records: Record<number, number> = {};
    private timeout: Record<number, any> = {};

    set(key: number, value: number, duration: number): boolean {
        const exist = !!this.records[key];
        this.records[key] = value;
        clearTimeout(this.timeout[key]);
        this.timeout[key] = setTimeout(() => {
            delete this.records[key];
        }, duration)
        return exist;
    }

    get(key: number): number {
        return this.records[key] ?? -1;
    }

	count(): number {
        return Object.keys(this.records).length
    }
}

/**
 * Your TimeLimitedCache object will be instantiated and called as such:
 * var obj = new TimeLimitedCache()
 * obj.set(1, 42, 1000); // false
 * obj.get(1) // 42
 * obj.count() // 1
 */
