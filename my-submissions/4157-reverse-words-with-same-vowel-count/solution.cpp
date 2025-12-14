class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        vector<int> vowels;
        string word = "";
        int vowelCount = 0;
        for (char &c : s) {
            if (c == ' ') {
                words.push_back(word);
                vowels.push_back(vowelCount);
                word = "";
                vowelCount = 0;
            }
            else if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                vowelCount++;
            }
            if (c != ' ')
                word.push_back(c);
        }
        words.push_back(word);
        vowels.push_back(vowelCount);
        vowelCount = vowels[0];
        string res = words[0];
        for (int i = 1; i < words.size(); ++i) {
            res.push_back(' ');
            if (vowelCount == vowels[i]) {
                string w = words[i];
                reverse(w.begin(), w.end());
                res += w;
            }
            else {
                res += words[i];
            }
        }
        return res;
    }
};
