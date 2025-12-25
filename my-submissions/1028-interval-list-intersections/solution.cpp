class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int n = firstList.size();
        int m = secondList.size();
        if (n == 0 || m == 0) return {};

        vector<vector<int>> interSections;
        int l = 0, r = 0;
        while (l < n && r < m) {
            int s1 = firstList[l][0];
            int e1 = firstList[l][1];
            int s2 = secondList[r][0];
            int e2 = secondList[r][1];

            int maxS = max(s1, s2);
            int minE = min(e1, e2);

            if (maxS <= minE)
                interSections.push_back({maxS, minE});
            if (e2 > e1)
                l++;
            else
                r++;
        }
        return interSections;
    }
};
