class Solution {
public:
    bool checkValidString(string s) {
        int MIN = 0, MAX = 0;
        for (char &c : s) {
            if (c == '(') {
                MIN++;
                MAX++;
            }
            else if (c == ')') {
                MIN--;
                MAX--;
            }
            else {
                MIN--;
                MAX++;
            }
            MIN = max(0, MIN);
            if (MAX < 0)
                return false;
        }
        return (MIN == 0);
    }
};
