/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var maxSubarrayLength = function (nums, k) {
    let i = 0;
    const freqMap = new Map()
    let maxLength = - Infinity
    for (let j = 0; j < nums.length; j++) {
        freqMap.set(nums[j], (freqMap.get(nums[j]) || 0) + 1)
        while (freqMap.get(nums[j]) > k) {
            freqMap.set(nums[i], freqMap.get(nums[i]) - 1)
            i++;
        }
        maxLength = Math.max(maxLength, j - i + 1)

    }
    return maxLength
};