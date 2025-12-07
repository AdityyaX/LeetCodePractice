class Solution {
    /*
    brute force approach for this can be let's iterate over array and return value
    optimized approach can be:-
    number of odd from 0 to n is n+1/2
    we can find from low-1 to high with this formula
    */
public:
    int countOdds(int low, int high) {
        int count = 0;
        while (low <= high) {
            if (low % 2) {
                count++;
            }
            low++;
        }
        return count;
    }
};