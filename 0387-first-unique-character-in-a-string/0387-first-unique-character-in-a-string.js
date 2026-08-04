/**
 * @param {string} s
 * @return {number}
 */
var firstUniqChar = function (s) {
    const freqMap = new Map()
    for (let st of s) {
        freqMap.set(st, (freqMap.get(st) || 0) + 1)
    }

    for (let i = 0; i < s.length; i++) {
        if (freqMap.get(s[i]) === 1) {
            return i;
        }
    }
    return -1;

};