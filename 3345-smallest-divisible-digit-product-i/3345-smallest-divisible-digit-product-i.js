/**
 * @param {number} n
 * @param {number} t
 * @return {number}
 */
var smallestNumber = function (n, t) {
    while (true) {
        product = 1
        temp = n
        while (temp > 0) {
            product = product * (temp % 10)
            temp = Math.floor(temp / 10)
        }
        if (product % t === 0) {
            return n;
        }
        n++
    }

};