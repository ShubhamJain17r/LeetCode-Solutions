class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (dict.count(endWord) == 0) return 0;
        int L = beginWord.length();
        unordered_map<string, vector<string>> patterns;
        for (string w : dict) {
            for (int i = 0; i < L; ++i) {
                string pat = w.substr(0,i) + '*' + w.substr(i + 1);
                patterns[pat].push_back(w);
            }
        }
        int steps = 1;
        queue<string> q;
        q.push(beginWord);
        unordered_set<string> visited;
        visited.insert(beginWord);
        while (!q.empty()) {
            int sz = q.size();
            while (sz--){
                string curr = q.front(); q.pop();
                if (curr == endWord) return steps;
                for (int i = 0; i < L; ++i) {
                    string pat = curr.substr(0, i) + '*' + curr.substr(i + 1);
                    for (const string& nei : patterns[pat]) {
                        if (!visited.count(nei)) {
                            visited.insert(nei);
                            q.push(nei);
                        }
                    }
                }
            }
            steps++;
        }
        return 0;
    }
};
