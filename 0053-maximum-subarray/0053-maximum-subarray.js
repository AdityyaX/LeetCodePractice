/**
 * @param {number[]} nums
 * @return {number}
 */
var maxSubArray = function (nums) {
    let maxSum = -Infinity
    let currentSum = 0
    for (let num of nums) {
        currentSum += num
        maxSum = Math.max(maxSum, currentSum);

        if (currentSum < 0) {
            currentSum = 0;
        }

    }

    return maxSum
};