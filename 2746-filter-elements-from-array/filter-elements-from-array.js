/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var filter = function(arr, fn) {
    let resultArr=[];
    for(let i=0; i<arr.length; i++){
        const valReturned = fn(arr[i], i);
        if(valReturned){
            resultArr.push(arr[i]);
        }
    }
    return resultArr;
};