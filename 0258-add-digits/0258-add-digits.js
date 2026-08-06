/**
 * @param {number} num
 * @return {number}
 */
function sumOfDigit(value) {
    let sum = 0
    while (value) {
        sum += value % 10
        value = Math.floor(value / 10)
    }
    return sum
}
var addDigits = function (num) {
    while (num >= 10) {
        num = sumOfDigit(num)
    }
    return num

};