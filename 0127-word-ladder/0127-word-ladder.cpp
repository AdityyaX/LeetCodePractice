class Solution {
public:
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {
        queue<pair<string, int>> qu;
        unordered_set<string> WordDict;
        qu.push({beginWord, 1});
        for (int i = 0; i < wordList.size(); i++) {
            WordDict.insert(wordList[i]);
        }
        while (!qu.empty()) {
            string word = qu.front().first;
            int step = qu.front().second;
            qu.pop();
            if (word == endWord)
                return step;
            for (int i = 0; i < word.size(); i++) {
                char orignal = word[i];
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    word[i] = ch;
                    if (WordDict.find(word) != WordDict.end()) {
                        WordDict.erase(word);
                        qu.push({word, step + 1});
                    }
                }
                word[i] = orignal;
            }
        }
        return 0;
    }
};