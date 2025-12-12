class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int i = 0;
        int j = 1;
        int maxP = 0;
        while (j < prices.size()) {
            if (prices[j] > prices[i]) {
                maxP = max(maxP, prices[j] - prices[i]);
            } else {
                i = j;
            }
            j++;
        }
        return maxP;
    }
};