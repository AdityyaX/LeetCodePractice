class Solution {
public:
    vector<string> result;

    void helper(int i, string& s, string& temp) {
        if (i == s.size()) {
            result.push_back(temp);
            return;
        }
        if (isalpha(s[i])) {
            temp.push_back(tolower(s[i]));
            helper(i + 1, s, temp);
            temp.pop_back();

            temp.push_back(toupper(s[i]));
            helper(i + 1, s, temp);
            temp.pop_back();
        } else {
            temp.push_back(s[i]);
            helper(i + 1, s, temp);
            temp.pop_back();
        }
    }

    vector<string> letterCasePermutation(string s) {
        string temp;
        helper(0, s, temp);
        return result;
    }
};
