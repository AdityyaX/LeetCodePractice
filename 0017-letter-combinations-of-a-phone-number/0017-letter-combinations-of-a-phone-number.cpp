class Solution {
public:
    vector<string> result;
    void helper(int i, unordered_map<char, string> digitToLetters,
                string digits, string str) {
        if (i == digits.size()) {
            result.push_back(str);
            return;
        }
        string letters = digitToLetters[digits[i]];
        for (char c : letters) {
            helper(i + 1, digitToLetters, digits, str + c);
        }
    }
    vector<string> letterCombinations(string digits) {
        if (digits.empty())
            return {};
        unordered_map<char, string> digitToLetters = {
            {'2', "abc"}, {'3', "def"},  {'4', "ghi"}, {'5', "jkl"},
            {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};

        helper(0, digitToLetters, digits, "");

        return result;
    }
};