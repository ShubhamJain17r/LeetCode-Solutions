class Solution {
private:
    void makePatterns(unordered_map<string, vector<string>> &patterns, string word) {
        for (int i = 0;i < word.length(); ++i) {
            string temp = word.substr(0,i) + '*' + word.substr(i + 1);
            patterns[temp].push_back(word);
        }
    }
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        bool isEndWordPresent = false;
        unordered_map<string, vector<string>> patterns;
        unordered_set<string> dict(wordList.begin(), wordList.end());

        makePatterns(patterns, beginWord);
        for (string &word : wordList) {
            if (word == endWord)
                isEndWordPresent = true;
            makePatterns(patterns, word);
        }

        if (!isEndWordPresent) return 0;

        dict.erase(beginWord);

        // for (auto &p : patterns) {
        //     cout<<p.first<<" : ";
        //     for (auto &w : p.second)
        //         cout<<w<<" ";
        //     cout<<endl;
        // }

        queue<string> q;
        q.push(beginWord);
        int levels = 0;
        while (!q.empty()) {
            int sz = q.size();
            levels++;
            while (sz--) {
                string word = q.front(); q.pop();
                if (word == endWord)
                    return levels;
                for (int i = 0;i < word.length(); ++i) {
                    string temp = word.substr(0,i) + '*' + word.substr(i + 1);
                    if (patterns.count(temp)) {
                        for (const string &w : patterns[temp]) {
                            if (dict.count(w)) {
                                dict.erase(w);
                                q.push(w);
                            }
                        }
                        patterns.erase(temp);
                    }
                }
            }
        }
        return 0;
    }
};
