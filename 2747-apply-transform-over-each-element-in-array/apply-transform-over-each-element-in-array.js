/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var map = function(arr, fn) {
    let returnArr=[];
    for(let i=0; i<arr.length; i++){
        const val = fn(arr[i], i);
        returnArr.push(val);
    }
    return returnArr;
};