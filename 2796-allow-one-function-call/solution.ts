type Fn = (...args: any[]) => any

function once(fn: Fn): Fn {
  let flag = false;
  return function (...args) {
    if(flag) return undefined;
    flag = true;
    return fn(...args)
  };
}

/**
 * let fn = (a,b,c) => (a + b + c)
 * let onceFn = once(fn)
 *
 * onceFn(1,2,3); // 6
 * onceFn(2,3,6); // returns undefined without calling fn
 */
