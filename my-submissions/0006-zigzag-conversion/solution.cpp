class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || numRows >= s.length()) return s;
        vector<string> VOS(numRows, "");
        bool goingDown = true;
        int i = 0;
        for (char c : s) {
            VOS[i].push_back(c);
            goingDown ? i++ : i--;
            if (i == 0 || i == numRows - 1)
                goingDown = !goingDown;
        }
        string res = "";
        for (string str : VOS) {
            res += str;
        }
        return res;
    }
};
