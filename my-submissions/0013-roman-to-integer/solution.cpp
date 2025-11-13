class Solution {
public:
    unordered_map<char, int> map = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000},
    };
    int romanToInt(string s) {
        int res = 0;
        char last = '\0';
        for (char c : s) {
            if (last != '\0' && map[last] < map[c]) {
                res -= map[last];
                res += (map[c] - map[last]);
            }
            else {
                res += map[c];
            }
            last = c;
        }
        return res;
    }
};
