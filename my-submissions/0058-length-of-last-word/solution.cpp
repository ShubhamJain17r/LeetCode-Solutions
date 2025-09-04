class Solution {
public:
    int lengthOfLastWord(string s) {
        int ed = s.length() - 1;
        while (ed >= 0 && s[ed] == ' ')ed--;

        int count = 0;
        while (ed >=0 && s[ed] != ' '){
            ed--;
            count++;
        }
        return count;
    }
};
