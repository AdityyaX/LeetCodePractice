class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int i = 0;
        int maxProfit = 0;
        for (int j = 0; j < prices.size(); j++) {
            if (prices[j] > prices[i]) {
                maxProfit = max(maxProfit, prices[j] - prices[i]);
            } else {
                i = j;
            }
        }
        return maxProfit;
    }
};