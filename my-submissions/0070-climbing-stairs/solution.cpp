class Solution {
public:
    int climbStairs(int n, unordered_map<int, int>& map) {
        if (n == 0)
            return 1;
        if (map.find(n) != map.end())
            return map[n];
        if (n < 0)
            return 0;
        map[n] = climbStairs(n - 1, map) + climbStairs(n - 2, map);
        return map[n];
    }
    int climbStairs(int n) {
        unordered_map<int, int> map;
        climbStairs(n, map);
        return map[n];
    }
};
