/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number[]}
 */
var topKFrequent = function (nums, k) {
    const freqMap = new Map()
    const result = []
    for (let num of nums) {
        freqMap.set(num, (freqMap.get(num) || 0) + 1)
    }
    const sortedMap =
        [...freqMap].sort((a, b) => b[1] - a[1])
    console.log("sortedMap", sortedMap)

    for (let i = 0; i < k; i++) {
        result.push(sortedMap[i][0])
    }



    return result;
};