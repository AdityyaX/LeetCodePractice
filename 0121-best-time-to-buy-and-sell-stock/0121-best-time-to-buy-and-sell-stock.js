/**
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function (prices) {
    let maxprofit = 0;
    let i = 0
    for (let j = 1; j < prices.length; j++) {
        if (prices[j] > prices[i]) {
            maxprofit = Math.max(maxprofit, prices[j] - prices[i])
        } else {
            i = j
        }

    }
    return maxprofit

};