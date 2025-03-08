type Fn = (...params: number[]) => number

function memoize(fn: Fn): Fn {
    const cache = {};
    let cnt = 0;

    return function(...args) {
        let input = JSON.stringify(args);
        return cache[input] ?? (cache[input] = fn(...args));
    }
}


/** 
 * let callCount = 0;
 * const memoizedFn = memoize(function (a, b) {
 *	 callCount += 1;
 *   return a + b;
 * })
 * memoizedFn(2, 3) // 5
 * memoizedFn(2, 3) // 5
 * console.log(callCount) // 1 
 */
