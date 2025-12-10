class Solution {
public:
    /*
    here logic for this can be
    for any value os arr if it is smaller than arr[0] then return 0
    else return from to end factorial of n*/
    int countPermutations(vector<int>& complexity) {
        int m = 1e9 + 7;
        long long result = 1;
        for (int i = 1; i < complexity.size(); i++) {
            if (complexity[i] <= complexity[0])
                return 0;

            result = (result * i) % m;
        }
        return result;
    }
};