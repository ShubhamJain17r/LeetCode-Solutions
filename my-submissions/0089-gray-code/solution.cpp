class Solution {
public:
    vector<int> grayCode(int n) {
        int sz = (1 << n);
        vector<int> res;
        res.reserve(sz);

        for (int i = 0; i < sz; ++i) {
            res.emplace_back(i ^ (i >> 1));
        }

        return res;
    }
};
