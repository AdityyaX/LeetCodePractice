/**
 * @param {string[]} strs
 * @return {string[][]}
 */
var groupAnagrams = function (strs) {
    const freqMap = new Map()
    for (const str of strs) {
        const sortedStr = str.split("").sort().join("")
        if (!freqMap.has(sortedStr)) {
            freqMap.set(sortedStr, []);
        }
        freqMap.get(sortedStr).push(str);
    }

    return [...freqMap.values()];
};