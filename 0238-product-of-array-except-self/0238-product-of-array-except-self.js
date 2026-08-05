/**
 * @param {number[]} nums
 * @return {number[]}
 */
var productExceptSelf = function (nums) {
    const n = nums.length;
    const result = new Array(n).fill(0);
    const prefixArray = new Array(n).fill(0);
    const suffixArray = new Array(n).fill(0);
    prefixArray[0] = 1
    suffixArray[suffixArray.length - 1] = 1
    for (let i = 1; i < nums.length; i++) {
        prefixArray[i] = prefixArray[i - 1] * nums[i - 1]
        console.log(prefixArray[i])
    }
    for (let i = nums.length - 2; i >= 0; i--) {
        suffixArray[i] = nums[i + 1] * suffixArray[i + 1]
        console.log(suffixArray[i])

    }

    for (let i = 0; i < nums.length; i++) {
        result[i] = suffixArray[i] * prefixArray[i]
    }
    return result
};