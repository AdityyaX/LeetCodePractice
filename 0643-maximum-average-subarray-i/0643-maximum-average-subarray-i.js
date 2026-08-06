/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var findMaxAverage = function (nums, k) {
    let i = 0;
    let sum = 0
    let maxSum = -Infinity;
    for (let j = 0; j < nums.length; j++) {
        sum += nums[j]
        if (j - i + 1 == k) {
            maxSum = Math.max(maxSum, sum)
            sum -= nums[i]
            i++
        }

    }

    return maxSum / k

};