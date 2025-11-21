class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.length() != goal.length()) return false;
        if (s == goal) return true;
        for (int i = 0; i < s.length(); ++i) {
            // cout<<(s.substr(i + 1) + s.substr(0, i))<<endl;
            if (goal == (s.substr(i + 1) + s.substr(0, i + 1))) 
                return true;
        }
        return false;
    }
};
