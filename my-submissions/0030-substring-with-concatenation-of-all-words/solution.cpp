class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        if (s.empty() || words.empty()) return res;

        int w = words[0].size();
        int k = words.size();
        int total = w * k;
        int n = s.size();

        unordered_map<string, int> need;
        for (auto &x : words) need[x]++;

        // Try w different offsets
        for (int offset = 0; offset < w; offset++) {
            unordered_map<string, int> window;
            int matched = 0;
            int left = offset;

            // Slide right pointer
            for (int right = offset; right + w <= n; right += w) {
                string word = s.substr(right, w);

                if (need.count(word)) {
                    window[word]++;

                    if (window[word] == need[word])
                        matched++;

                    // If window is invalid (too many repeats)
                    while (window[word] > need[word]) {
                        string leftWord = s.substr(left, w);
                        if (window[leftWord] == need[leftWord])
                            matched--;
                        window[leftWord]--;
                        left += w;
                    }

                    // If full match
                    if (matched == need.size()) {
                        res.push_back(left);
                        // Move window by 1 word
                        string leftWord = s.substr(left, w);
                        if (window[leftWord] == need[leftWord])
                            matched--;
                        window[leftWord]--;
                        left += w;
                    }
                }

                // Word not in dictionary — reset window entirely
                else {
                    window.clear();
                    matched = 0;
                    left = right + w;
                }
            }
        }

        return res;
    }
};

