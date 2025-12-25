class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = needle.size();
        if (n == 0)
            return 0;
        int i = 0;
        for (int j = 0; j + n <= haystack.size(); j++) {
            string str = haystack.substr(j, n);
            if (haystack.substr(j, n) == needle)
                return j;
        }
        return -1;
    }
};