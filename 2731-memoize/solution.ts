type Fn = (...params: any) => any

function memoize(fn: Fn): Fn {
    var records = {};
    
    return function(...args) {
        let result = records[JSON.stringify([...args])];
        if(result !== undefined) return result; 
        result = fn(...args);
        records[JSON.stringify([...args])] = result
        return result;
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
