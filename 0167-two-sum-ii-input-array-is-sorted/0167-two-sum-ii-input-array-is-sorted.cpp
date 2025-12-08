class Solution {
public:
    /*
    one intution here can be lets run two for loop and calculate the sum
    second can be using hashmap here
    optimal apprach is using two pointer approach here 
    */
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0, j = numbers.size() - 1;
        int sum = 0;
        while (i < j) {
            sum = numbers[i] + numbers[j];
            if (sum < target) {
                i++;
            } else if (sum > target) {
                j--;
            } else {
                return {i + 1, j + 1};
            }
        }
        return {-1, -1};
    }
};