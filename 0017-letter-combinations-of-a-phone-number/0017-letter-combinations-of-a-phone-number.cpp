class Solution {
public:
    unordered_map<char, string> digitToLetters = {
        {'2', "abc"}, {'3', "def"},  {'4', "ghi"}, {'5', "jkl"},
        {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};

    vector<string> result;
    void helper(int i, string current, string digits) {
        if (i == digits.size()) {
            result.push_back(current);
        }
        string temp = digitToLetters[digits[i]];
        for (char ch : temp) {
            helper(i + 1, current + ch, digits);
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.empty())
            return {};
        string current;
        helper(0, current, digits);
        return result;
    }
};