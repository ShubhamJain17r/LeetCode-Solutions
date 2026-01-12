class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> in_degree(n + 1, 0);
        vector<int> out_degree(n + 1, 0);

        for (const vector<int> &p : trust) {
            int from = p[0], to = p[1];
            out_degree[from]++;
            in_degree[to]++;
        }

        for (int i = 1; i <= n; ++i) {
            if (in_degree[i] == n - 1 && out_degree[i] == 0) return i;
        }
        return -1;
    }
};
