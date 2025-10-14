class Solution {
public:
    bool isPalindrome(string str){
        int s = 0, e = str.length() - 1;
        while (s < e){
            if (str[s++] != str[e--]) return false;
        }
        return true;
    }
    void partition(string& s,vector<string>& subset, vector<vector<string>>& ans, int idx){
        if (idx == s.length()){
            ans.push_back(subset);
            return;
        }
        for (int i = idx; i < s.length(); ++i){
            string curr = s.substr(idx, i - idx + 1);
            if (!isPalindrome(curr)) continue;;
            subset.push_back(curr);
            partition(s, subset, ans, i + 1);
            subset.pop_back();
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> subset;

        partition(s, subset, ans, 0);

        return ans;
    }
};
