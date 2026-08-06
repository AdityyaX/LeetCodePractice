/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var search = function (nums, target) {
    let start = 0;
    let last = nums.length - 1
    while (start <= last) {
       let mid = start + Math.floor((last - start) / 2);
        if (nums[mid] == target) return mid
        if (nums[mid] > target) {
            last = mid - 1
        } else {
            start = mid + 1
        }
    }

    return -1
};