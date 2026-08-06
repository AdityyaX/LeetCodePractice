/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number[]}
 */
var nextGreaterElement = function (nums1, nums2) {
    const result = [];
    for (let num of nums1) {
        let index = -1

        for (let i = 0; i < nums2.length; i++) {
            if (nums2[i] == num) {
                index = i;
                break;
            }
        }
        console.log("index", index)
        let nextGreater = -1
        for (let j = index + 1; j < nums2.length; j++) {
            if (nums2[j] > num) {
                nextGreater = nums2[j]
                break;
            }
        }
        result.push(nextGreater)
    }
    return result
};