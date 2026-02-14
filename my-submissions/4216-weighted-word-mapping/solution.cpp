class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans = "";
        for (const string &str : words) {
            int sum = 0;
            for (const char &c : str) {
                sum += weights[c - 'a'];
            }
            sum = sum % 26;
            ans.push_back('z' - sum);
        }
        return ans;
    }
};
