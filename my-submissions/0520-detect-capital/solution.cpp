class Solution {
public:
    bool isCapital(char c) {
        return (c >= 'A' && c <='Z');
    }
    bool detectCapitalUse(string word) {
        bool firstCapital = isCapital(word[0]);
        bool allCapital = firstCapital, allSmall = !firstCapital;
        if (!firstCapital) {
            firstCapital = false;
        }
        for (int i = 1; i < word.length(); ++i) {
            if (firstCapital && isCapital(word[i]))
                firstCapital = false;
            if (allSmall && isCapital(word[i])) {
                allSmall = false;
            }
            if (allCapital && !isCapital(word[i])) {
                allCapital = false;
            }
        }
        return firstCapital || allSmall || allCapital;
    }
};
