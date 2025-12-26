class Solution {
public:
    /*
     */
    int bestClosingTime(string customers) {

        int penalty = 0;
        for (char ch : customers) {
            if (ch == 'Y')
                penalty++;
        }
        int cost = 0;
        int minPenalty = penalty;
        for (int i = 0; i < customers.size(); i++) {
            if (customers[i] == 'Y') {
                penalty--;
            } else {
                penalty++;
            }

            if (penalty < minPenalty) {
                minPenalty = penalty;
                cost = i + 1;
            }
        }
        return cost;
    }
};