class Solution {
public:
    int fibHelper(int n, unordered_map<int, int>& map) {
        if (n == 0 || n == 1) 
            return n;
        if (map.find(n) != map.end())
            return map[n];
        map[n] = fibHelper(n - 1, map) + fibHelper(n - 2, map);
        return map[n];
    }
    int fib(int n) {
        unordered_map<int, int> map;
        return fibHelper(n, map);
    }
};
