class Solution {
public:
    /*
    firstly we will add all the elements in right map then for every index we
    will remove it from right map check if 2*num is in left and right map then
    insert num in left map

    */
    int M = 1E9 + 7;

    int specialTriplets(vector<int>& nums) {
        unordered_map<int, int> leftTriplet;
        unordered_map<int, int> rightTriplet;
        int result = 0;
        for (int num : nums) {
            rightTriplet[num]++;
        }
        for (int num : nums) {
            rightTriplet[num]--;
            int left = leftTriplet[2 * num];
            int right = rightTriplet[2 * num];
            result = (result + (1LL * left * right)) % M;
            leftTriplet[num]++;
        }
        return result;
    }
};