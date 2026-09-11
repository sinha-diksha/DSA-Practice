/**
 * @param {Function} fn
 * @return {Function}
 */
 let callCount=0;

function memoize(fn) {
    const map = new Map();
    return function(...args) {
        let str=JSON.stringify(args);
        console.log(str);
        if(map.get(str)!==undefined) return map.get(str);
        callCount++;
        let val =fn(...args);
        map.set(str, val);
        return val;
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