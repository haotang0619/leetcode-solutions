class TimeLimitedCache {
    private cache = {};
    
    constructor() {}
    
    set(key: number, value: number, duration: number): boolean {
        let result = false;
        if(!!this.cache[key]) {
            result = true;
            clearTimeout(this.cache[key]?.timeout);
        } 
        let timeout = setTimeout(() => { delete this.cache[key]; }, duration);
        this.cache[key] = { value, timeout };
        return result;
    }
    
    get(key: number): number {
        return this.cache[key]?.value ?? -1; 
    }
    
    count(): number {
        return Object.keys(this.cache).length;
    }
}

/**
 * const timeLimitedCache = new TimeLimitedCache()
 * timeLimitedCache.set(1, 42, 1000); // false
 * timeLimitedCache.get(1) // 42
 * timeLimitedCache.count() // 1
 */
