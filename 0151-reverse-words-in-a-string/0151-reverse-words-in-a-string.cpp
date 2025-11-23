class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        string str = "";
        s += " ";
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == ' ') {
                if (!str.empty()) {
                    st.push(str);
                    str = "";
                }
            } else {
                str += s[i];
            }
        }
        string result = "";
        while (st.size() != 1) {
            string temp = st.top();
            st.pop();
            result += (temp + ' ');
        }
        result += st.top();
        return result;
    }
};