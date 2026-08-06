/**
 * @param {number[]} nums
 * @return {number}
 */
var majorityElement = function (nums) {
    let i = 0;
    let j = nums.length
    let el = nums[0]
    let count = 0
    while (i < j) {
        if (count == 0) {
            el = nums[i]
        }
        if (nums[i] == el) {
            count++;
        } else {
            count--
        }
        i++;
    }
    let count2 = 0
    let n = nums.length
    for (let i = 0; i < nums.length; i++) {
        if (nums[i] == el) {
            count2++;
        }
        if (count2 > Math.floor(n / 2)) {
            return el
        }
    }

    return -1
};