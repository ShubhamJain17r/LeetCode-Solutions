class Solution {
public:
    unordered_map<char, string> m = {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
    };

    void generateCombinations(string digits,string curr ,vector<string>& ans, int i){
        if (i == digits.length()){
            ans.push_back(curr);
            return;
        }
        char digit = digits[i];
        for (char c : m[digit]){
            curr.push_back(c);
            generateCombinations(digits, curr, ans, i+1);
            curr.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if (digits.length() == 0) return ans;
        string curr = "";
        generateCombinations(digits, curr, ans, 0);

        return ans;
    }
};
