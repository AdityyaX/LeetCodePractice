class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int i = 0;
        unordered_map<int, int> countMap;
        int maxcount = 0;
        for (int j = 0; j < fruits.size(); j++) {
            countMap[fruits[j]]++;
            while (countMap.size() > 2) {
                countMap[fruits[i]]--;
                if (countMap[fruits[i]] == 0) {
                    countMap.erase(fruits[i]);
                }
                i++;
            }
            maxcount = max(maxcount, j - i + 1);
        }
        return maxcount;
    }
};