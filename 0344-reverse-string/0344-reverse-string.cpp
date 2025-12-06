class Solution {
public:
    /*
    there can be multiple approach for this stack ,array,builtin
    but best approach will be this O(N) time and O(1) space complexiety,*/
    void reverseString(vector<char>& s) {
        int j = s.size() - 1;
        int i = 0;
        while (i <= j) {
            swap(s[i], s[j]);
            i++;
            j--;
        }
        return;
    }
};