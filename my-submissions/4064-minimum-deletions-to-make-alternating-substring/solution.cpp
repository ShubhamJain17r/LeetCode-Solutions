class Fenwick {
    vector<int> bit;
    int n;

public:
    Fenwick(int n) : n(n), bit(n + 1, 0) {}

    void update(int i, int delta) {
        for (++i; i <= n; i += i & -i)
            bit[i] += delta;
    }

    int query(int i) {
        int s = 0;
        for (++i; i > 0; i -= i & -i)
            s += bit[i];
        return s;
    }

    int range(int l, int r) {
        return query(r) - query(l - 1);
    }
};

class Solution {
public:
    vector<int> minDeletions(string s, vector<vector<int>>& queries) {
        int n = s.size();
        Fenwick ft(n);

        // Initialize bad array
        for (int i = 1; i < n; ++i) {
            if (s[i] == s[i - 1])
                ft.update(i, 1);
        }

        vector<int> ans;

        for (auto &q : queries) {
            if (q[0] == 1) {
                int idx = q[1];

                // remove old contributions
                if (idx > 0 && s[idx] == s[idx - 1])
                    ft.update(idx, -1);
                if (idx + 1 < n && s[idx] == s[idx + 1])
                    ft.update(idx + 1, -1);

                // toggle
                s[idx] = (s[idx] == 'A' ? 'B' : 'A');

                // add new contributions
                if (idx > 0 && s[idx] == s[idx - 1])
                    ft.update(idx, 1);
                if (idx + 1 < n && s[idx] == s[idx + 1])
                    ft.update(idx + 1, 1);
            }
            else {
                int l = q[1], r = q[2];
                if (l < r)
                    ans.push_back(ft.range(l + 1, r));
                else
                    ans.push_back(0);
            }
        }
        return ans;
    }
};

