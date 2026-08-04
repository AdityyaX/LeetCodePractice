/**
 * @param {number} num
 * @return {number}
 */
function isSingleDigit(num) {
    return Number.isInteger(num) && Math.abs(num) < 10;
}
function sumOfDigits(value) {
    let sum = 0;
    while (value) {
        sum += value % 10;
        value = Math.floor(value / 10)
    }
    return sum
}
var addDigits = function (num) {
    let sum = 0;
    sum = sumOfDigits(num)
    while (!isSingleDigit(sum)) {
        sum = sumOfDigits(sum)
    }
    return sum;

};