/**
 * @param {string[]} strs
 * @return {string}
 */
var longestCommonPrefix = function (strs) {
    strs.sort();
    let result = ""
    const firstString = strs[0]
    const secondString = strs[strs.length - 1]


    for (let i = 0; i < strs[0].length; i++) {
        if (firstString[i] === secondString[i]) {
            result += firstString[i]
        } else {
            return result
        }
    }

    return result
};