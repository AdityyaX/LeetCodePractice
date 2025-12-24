/**
 * @param {Array} arr
 * @param {number} depth
 * @return {Array}
 */
var flat = function (arr, n) {
    let result = [];
    for (let x of arr) {
        if (Array.isArray(x) && n > 0) {
            result.push(...flat(x, n - 1));
        } else {
            result.push(x);
        }
    }

    return result;
};