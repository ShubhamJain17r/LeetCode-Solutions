class Solution {
public:
    void helper(int n, vector<string>& ans, string curr, int o, int c){
        if (o == n && c == n){
            ans.push_back(curr);
            return;
        }
        if (o == c){
            helper(n, ans, curr + '(', o + 1, c);
        }
        else if (o == n){
            helper(n, ans, curr + ')', o, c + 1);
        }
        else{
            helper(n, ans, curr + '(', o + 1, c);
            helper(n, ans, curr + ')', o, c + 1);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string curr = "";
        helper(n, ans, curr, 0,0);
        return ans;
    }
};
