/**
 * @param {number} x
 * @param {number} n
 * @return {number}
 */
var myPow = function (x, n) {
    let result = 1
    let power = Math.abs(n)
    while (power) {
        if (power % 2 === 1) {
            result *= x
        }
        x *= x
        power = Math.floor(power / 2)
    }
    return n > 0 ? result : 1 / result
};