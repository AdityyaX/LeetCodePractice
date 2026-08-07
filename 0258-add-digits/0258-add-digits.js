/**
 * @param {number} num
 * @return {number}
 */
function findsSum(num) {
    let result = 0
    while (num) {
        result = result + num % 10
        num = Math.floor(num / 10)
    }
    return result
}
var addDigits = function (num) {
    while (num >= 10) {
        num = findsSum(num)
    }
    return num

};