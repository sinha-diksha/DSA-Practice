/**
 * @param {number[]} nums
 * @param {Function} fn
 * @param {number} init
 * @return {number}
 */
var reduce = function(nums, fn, init) {
    let initialVal=init;
    for(let i=0; i<nums.length; i++){
        let value = fn(initialVal, nums[i]);
        initialVal=value;
    }
    return initialVal;
};