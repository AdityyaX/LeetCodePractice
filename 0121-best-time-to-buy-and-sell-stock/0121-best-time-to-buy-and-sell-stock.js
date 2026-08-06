var maxProfit = function (prices) {
    let buy = 0;
    let maxProfit = 0;

    for (let sell = 1; sell < prices.length; sell++) {
        if (prices[sell] > prices[buy]) {
            maxProfit = Math.max(maxProfit, prices[sell] - prices[buy]);
        } else {
            buy = sell;
        }
    }

    return maxProfit;
};